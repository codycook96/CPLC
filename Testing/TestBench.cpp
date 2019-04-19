#include "TestBench.h"


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
        catch(const std::exception &e){
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

/*
void TestBench::test(){
    Test* t;
    while(tests.size() > 0){
        t = tests.at(0);

        std::ofstream file;
        file.open(outpath);

        file << t->getInfo();

        t->run();

        
        if(t->getErr()){
            file << t->getError();
        }
        else{
            file << t->getReport();
        }
        
        file.close();
        delete t;
        tests.erase(tests.begin());
    }
}
*/

void TestBench::test(std::string testName){
    if(tests.find(testName) == tests.end()){
        std::cout << "No such test exists" << std::endl;
    }
    else{
        Test* t = tests.at(testName);

        t->run();

        const time_t ctt = time(0);
        tm* lt = localtime(&ctt);
        std::string dt = std::to_string(lt->tm_mon + 1) + std::string("-") + std::to_string(lt->tm_mday) + std::string("-") + std::to_string(lt->tm_year + 1900) + std::string("_") + std::to_string(lt->tm_hour) + std::string(":") + std::to_string(lt->tm_min) + std::string(":") + std::to_string(lt->tm_sec);
        std::string outfile = path + "Results_" + t->getName() + std::string("_") + dt + std::string(".txt");
        std::cout << "Output file: " << outfile << std::endl;
        std::ofstream file;
        file.open(std::string(outfile));
        
        file << "[TEST]/n" << t->getName() << std::endl;
        file << "[PASS RATE]/n" << t->passRate() * 100 << "%" <<  std::endl;
        file << "[ERROR RATE]/n" << t->errorRate() * 100 << "%" <<  std::endl;
        file << "[INFO]/n" << std::endl;
        file << t->getInfo();
        if(t->errorOccured()){
            file << "[ERRORS]/n" << std::endl;
            file << t->getError();
        }
        file << "[REPORT]/n" << std::endl;
        file << t->getReport();

        file.close();
    }
}

void TestBench::test(std::vector<std::string> testNames){

}