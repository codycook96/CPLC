#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <unordered_map> 
#include <exception>
#include <ctime>

#include "Exception.h"

class TestException: public Exception{
    private:
        int caseNum;

    public:
        explicit TestException(std::string _msg, std::string _throwFile = "", int _throwLine = 0, int _caseNum = 0);
        const std::string read() const;
};

class Test{
    private:
        //Test Name
        std::string name;
        
        //Case Result Vectors
        std::vector<bool> passedFlags;
        std::vector<bool> errorFlags;

        //Case Vector
        std::vector<std::function<bool()>> cases;

        //Private Streams
        std::stringstream error;

    public:
        //Constructors
        Test();
        Test(const Test& _test);
        Test(std::string _name);
        
        //Add Case
        void addCase(std::function<bool()> t);

        //Run Test
        void run();
        
        //Public Streams
        std::stringstream report;
        std::stringstream info;

        //Test Statistics
        double passRate();
        double errorRate();

        bool errorOccured();

        //Accessors
        void setName(std::string n);
        std::string getName() const;
        std::string getError() const;
        std::string getReport() const;
        std::string getInfo() const;
};


class TestBench{
    private:
       std::string path;
       std::unordered_map<std::string, Test*> tests;
       //std::vector<Test*> tests;

    public:
        TestBench();
        void setPath(std::string p);
        //void addTest(Test t);
        //void addTest(std::string n, std::function<bool()> t);
        void addTest(Test* test, std::string testName);
        std::vector<std::string> testList();
        void test(std::string testName);
        void test(std::vector<std::string> testNames);


};

#endif