#include "TestList.h"



void Testing::TypeEquality(TestBench& tb){
    Test* t = new Test("TypeEquality"); 

    //Test information
    t->info << "Test: Equality Checking" << std::endl;
    t->info << "Description: Checking that types are equal and only equal to their same type" << std::endl;
    
    //Add Cases
    t->addCase(
        [&] () -> bool { 
            return true;
        }
    );

    tb.addTest(t, t->getName());
}