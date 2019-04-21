#include "TestList.h"



void Testing::TypeComparison(TestBench& tb){
    Test& t = *(new Test("TypeComparison")); 

    //Test information
    t.info << "Checking that generic types accept their proper child types" << std::endl;
    
    //Add Cases
    //Case 1
    t.addCase(
        [&] () -> bool { 
            t.report << "This one is true" << std::endl;
            return true;
        }
    );
    //Case 2
    t.addCase(
        [&] () -> bool { 
            //t->report << "This one is false" << std::endl;
            return false;
        }
    );
    //Case 3
    t.addCase(
        [&] () -> bool { 
            //t->report << "This one is true" << std::endl;
            return true;
        }
    );
    //Case 4
    t.addCase(
        [&] () -> bool { 
            //t->report << "This one is error" << std::endl;
            throw TestException("Error could not do the thing.", "TypeComparison.cpp", 37, 4);
        }
    );
    //Case 5
    t.addCase(
        [&] () -> bool { 
            //t->report << "This one is true" << std::endl;
            return true;
        }
    );
    
    tb.addTest(&t, t.getName());
}