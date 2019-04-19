#include "TestList.h"

//using namespace Testing;

void Testing::TypeIDAccept(TestBench& tb){
    Test* t = new Test("TypeIDAccept");    

    //Test information
    t->info << "Test: Equality Checking" << std::endl;
    t->info << "Description: Checking that types are equal and only equal to their same type" << std::endl;

    //Add Cases
    t->addCase(
        [&] () -> bool { 
            t->report << "Test" << std::endl; 

            return true; 
        }
    );

    tb.addTest(t, t->getName());
}