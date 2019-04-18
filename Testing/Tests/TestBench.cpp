#include "TestBench.h"

/*
Test::Test(Test t){
    name = t.getName();
    passed = t.getPassed();
    error = t.getError();
    test = t.getTest();
    errorReport = _t.getErrorReport;
    report = t.report;
}
*/
Test::Test(){
}

Test::Test(const Test& t){

}

void Test::run(){
    /*
    try{
        pass = test();
    }
    catch (const std::exception &e){
        err = true;
        error << e.what();
    }
    catch(...){
        err = true;
        error << "Generic Exception" << std::endl;
    }
    if(error){
        pass = false;
    }
    */
}

void Test::addCase(std::function<bool()> c){
    //test = t;
}

std::string Test::getName(){
    return name;
}

std::string Test::getError(){
    return error.str();
}

std::string Test::getReport(){
    return report.str();
}

std::string Test::getDescription(){
    return description.str();
}

TestBench::TestBench(){

}

void TestBench::setPath(std::string p){
    const time_t ctt = time(0);
    tm* lt = localtime(&ctt);
    std::string dt = std::to_string(lt->tm_mon + 1) + std::string("-") + std::to_string(lt->tm_mday) + std::string("-") + std::to_string(lt->tm_year + 1900) + std::string("_") + std::to_string(lt->tm_hour) + std::string(":") + std::to_string(lt->tm_min) + std::string(":") + std::to_string(lt->tm_sec);
    outpath = p + "Results" + std::string("_") + dt + std::string(".txt");
}

void TestBench::addTest(Test* t){
    tests.push_back(t);
}

void TestBench::test(){
    Test* t;
    while(tests.size() > 0){
        t = tests.at(0);

        std::ofstream file;
        file.open(outpath);

        file << t->getDescription();

        t->run();

        /*
        if(t->getErr()){
            file << t->getError();
        }
        else{
            file << t->getReport();
        }
        */
        file.close();
        delete t;
        tests.erase(tests.begin());
    }
}