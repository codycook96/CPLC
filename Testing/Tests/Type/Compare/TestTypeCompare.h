#include "TestBench.h"
#include "Type.h"
#include "Database.h"

void TestTypeCompare(TestBench& tb){
    //Set Output Path
    tb.setPath("Results/Type/Compare/");

    //Add Tests
    //Test 1
    Test* t1 = new Test(); 
    t1->description << "Test: Equality Checking" << std::endl;
    t1->description << "Description: Checking that types are equal and only equal to their same type" << std::endl;
    t1->setTest(
        [&] () -> bool { 
            t1->report << "Test" << std::endl; 
            
            LREAL mylreal(467.93813);
            std::cout << "mylreal: " << mylreal.get() << std::endl;
            mylreal.set(1599493.2345);
            std::cout << "mylreal: " << mylreal.get() << std::endl;
            LREAL mylreal2(64.2);
            std::cout << "mylreal2: " << mylreal2.get() << std::endl;
            mylreal2 = mylreal;
            std::cout << "mylreal2: " << mylreal2.get() << std::endl;
            mylreal2.set(1.2);
            //std::cout << "Type mylreal:" << mylreal2.typeID() << std::endl;
            std::cout << "mylreal2: " << mylreal2.get() << std::endl;
            std::cout << "mylreal: " << mylreal.get() << std::endl;
            mylreal.set(50.9999);
            std::cout << "mylreal2: " << mylreal2.get() << std::endl;
            std::cout << "mylreal: " << mylreal.get() << std::endl;

            //std::cout << "a: " << (mybig.get().a.get()) << std::endl;
            //std::cout << "b: " << (mybig.get().b.get()) << std::endl;
            return true; 
        }
    );
    tb.addTest(t1);

    //Test 2



    //Run Tests
    tb.test();
}