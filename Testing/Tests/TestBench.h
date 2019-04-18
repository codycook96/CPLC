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
        //Test Name
        std::string name;
        
        //Test Output Path
        std::string outputFile;
        
        //Case Result Vectors
        std::vector<bool> pass;
        std::vector<bool> err;

        //Case Vector
        std::vector<std::function<bool()>> cases;

        //Private Streams
        std::stringstream error;

    public:
        //Constructors
        Test();
        Test(const Test& t);
        
        //Add Case
        void addCase(std::function<bool()> t);

        //Run Test
        void run();
        
        //Public Streams
        std::stringstream report;
        std::stringstream description;



        //void setTest(std::function<bool()> t);
        std::string getName();
        //bool getPass();
        //bool getErr();
        //std::function<bool()> getTest();
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