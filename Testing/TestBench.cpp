#include "TestBench.h"

//Create Directory
#include <sys/stat.h> 
#include <sys/types.h>

TestException::TestException(std::string _msg, std::string _throwFile, int _throwLine, int _caseNum): Exception(_msg, _throwFile, _throwLine), caseNum(_caseNum){}

const std::string TestException::read() const{
    std::stringstream ss;
    ss << msg << "\t" << "[file: " << throwFile << ", on line: " << throwLine << ", for test case: " << caseNum << "]" << std::endl;
    return ss.str();
}

Test::Test(){

}

Test::Test(const Test& _test){
    name = _test.getName();
}

Test::Test(std::string _name): name(_name){}

void Test::run(){
    bool tempPass = false;
    bool tempErr = false;

    passedFlags.clear();
    errorFlags.clear();

    for(unsigned int i = 0; i < cases.size(); i++){
        tempPass = false;
        tempErr = false;

        try{
            tempPass = cases.at(i)();
        }
        catch(const TestException& e){
            tempErr = true;
            error << e.read();
        }
        catch(const std::exception& e){
            tempErr = true;
            error << e.what();
        }
        catch(...){
            tempErr = true;
            error << "Generic Exception" << std::endl;
        }
        if(tempErr){
            tempPass = false;
        }

        passedFlags.push_back(tempPass);
        errorFlags.push_back(tempErr);
    }
}

void Test::addCase(std::function<bool()> c){
    cases.push_back(c);
}

double Test::passRate(){
    int passedNum = 0;

    for(unsigned int i = 0; i < passedFlags.size(); i++){
        if (passedFlags.at(i) == true){
            passedNum++;
        }
    }

    return ((double) passedNum)/((double) passedFlags.size()); 
}

double Test::errorRate(){
    int errorNum = 0;

    for(unsigned int i = 0; i < errorFlags.size(); i++){
        if (errorFlags.at(i) == true){
            errorNum++;
        }
    }
    
    return ((double) errorNum)/((double) errorFlags.size()); 
}

bool Test::errorOccured(){
    for(unsigned int i = 0; i < errorFlags.size(); i++){
        if (errorFlags.at(i) == true){
            return true;
        }
    }
    return false;
}

void Test::setName(std::string n){
    name = n;
}

std::string Test::getName() const{
    return name;
}

std::string Test::getError() const{
    return error.str();
}

std::string Test::getReport() const{
    return report.str();
}

std::string Test::getInfo() const{
    return info.str();
}

TestBench::TestBench(){

}

void TestBench::setPath(std::string p){
    path = p;
}

void TestBench::addTest(Test* test, std::string testName){
    tests.insert(std::make_pair(testName, test));
}

std::vector<std::string> TestBench::testList(){
    std::vector<std::string> list;
    for(std::unordered_map<std::string, Test*>::const_iterator it = tests.begin(); it != tests.end(); ++it){
        list.push_back(it->first);
        //std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n";
    }
    return list;
}

void TestBench::test(std::string testName){
    if(tests.find(testName) == tests.end()){
        std::cout << "No such test exists" << std::endl;
    }
    else{
        Test* t = tests.at(testName);

        t->run();


        
        
        std::stringstream ss;
        //file.open(std::string(outfile));
        
        ss << "[TEST]\t" << t->getName() << std::endl;
        ss << "[PASS]\t" << t->passRate() * 100 << "%" <<  std::endl;
        ss << "[ERR]\t" << t->errorRate() * 100 << "%" <<  std::endl;
        ss << "[INFO]\n";
        ss << t->getInfo() << std::endl;

        std::cout << ss.str();

        if(t->errorOccured()){
            ss << "[ERRORS]\n";
            ss << t->getError() << std::endl;
        }
        ss << "[REPORT]\n";
        ss << t->getReport() << std::endl;
        
        //@ ts-ignore
        if(mkdir((path + t->getName()).c_str(), 0777) == 0){
            std::cout << "Made directory " << path + t->getName().c_str() << std::endl;
        }

        const time_t ctt = time(0);
        tm* lt = localtime(&ctt);
        std::string dt = std::to_string(lt->tm_mon + 1) + std::string("-") + std::to_string(lt->tm_mday) + std::string("-") + std::to_string(lt->tm_year + 1900) + std::string("_") + std::to_string(lt->tm_hour) + std::string("-") + std::to_string(lt->tm_min) + std::string("-") + std::to_string(lt->tm_sec);
        std::string outfile = path + t->getName() + "/Results_"  + dt + ".txt";
        std::fstream file(outfile, std::ios::out);
        if(!file.is_open()){
            std::cout << "Couldnt not open!" << std::endl;
        }
        else{        
            std::cout << "Output file: " << outfile << std::endl;
            file << ss.str();
        }
        file.close();

        std::string printRest = "";
        while(printRest != "y" && printRest != "Y" && printRest != "n" && printRest != "N"){
            std::cout << "Print Report and Errors? (y/n): ";
            std::cin >> printRest;
        }
        if(printRest == "y" || printRest == "Y"){
            if(t->errorOccured()){
                std::cout << "[ERRORS]\n";
                std::cout << t->getError() << std::endl;
            }
            std::cout << "[REPORT]\n";
            std::cout << t->getReport() << std::endl;
        }
        if(printRest == "n" || printRest == "N"){
            return;
        }
    }
}

void TestBench::test(std::vector<std::string> testNames){
    for(unsigned int i = 0; i < testNames.size(); i++){
        test(testNames.at(i));
    }
}