#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <functional>
#include <exception>
#include <ctime>

class Test{
    private:
        std::string name;
        bool pass;
        bool err;
        std::function<bool()> test;
        std::stringstream error;
    public:
        //Constructors
        Test();
        //Test(Test t);
        Test(std::string _name, std::function<bool()> _test);

        //Public Members
        std::stringstream report;
        std::stringstream description;
        
        //Public Functions
        void run();

        //Accessors
        void setTest(std::function<bool()> t);
        std::string getName();
        bool getPass();
        bool getErr();
        std::function<bool()> getTest();
        std::string getError();
        std::string getReport();
        std::string getDescription();

};


class TestBench{
    private:
       std::string outpath;
       std::vector<Test*> tests;

       double accuracy;

    public:
        TestBench();
        void setPath(std::string p);
        //void addTest(Test t);
        //void addTest(std::string n, std::function<bool()> t);
        void addTest(Test* t);
        void test();


};

#endif