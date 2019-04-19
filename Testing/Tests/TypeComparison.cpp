#include "TestList.h"

//using namespace Testing;

void Testing::TypeComparison(TestBench& tb){
    Test* t = new Test("TypeComparison"); 

    //Test information
    t->info << "Test: Type Comparison Checking" << std::endl;
    t->info << "Description: Checking that generic types accept their proper child types" << std::endl;
    Test& t1 = *t;
    //Add Cases
    t->addCase(
        [&] () -> bool { 
            t1.report << "This one is true" << std::endl;
            return true;
        }
    );

    t->addCase(
        [&] () -> bool { 
            //t->report << "This one is false" << std::endl;
            return false;
        }
    );

    t->addCase(
        [&] () -> bool { 
            //t->report << "This one is true" << std::endl;
            return true;
        }
    );
    
    t->addCase(
        [&] () -> bool { 
            //t->report << "This one is error" << std::endl;
            throw "Howdy";
        }
    );

    t->addCase(
        [&] () -> bool { 
            //t->report << "This one is true" << std::endl;
            return true;
        }
    );
    
    tb.addTest(t, t->getName());
}