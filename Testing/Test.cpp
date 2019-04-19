#include <iostream>

#include "TestBench.h"
#include "TestList.h"


int main(int argc, char* argv[]){
    //Get commandline arguments
	std::vector<std::string> arguments;
	for(int i = 1; i < argc; i++){
		arguments.push_back(argv[i]);
	}

    //Test Flags
    //bool Test_Database_TypeCompare = false;


    //Set Test Flags
    for(unsigned int i = 0; i < arguments.size(); i++){
        if(arguments.at(i) == "TypeCompare" || arguments.at(i) == "All"){  }
    }

    TestBench* tb = new TestBench();
    tb->setPath("Results/");

    //Call Tests
    Testing::TypeEquality(*tb);
    Testing::TypeComparison(*tb);
    //Testing::TypeCasting(*tb);
    Testing::TypeIDAccept(*tb);
    //Testing::TypeSetGet(*tb);

    //--------TYPE TESTING--------//
    //COMPARE
    //if(runTestTypeCompare){ 
        //TestTypeCompare(*tb); 
    //}
    while(true){
        std::cout << "Enter test name: " << std::endl;
        std::string testName;
        std::cin >> testName;
        tb->test(testName);
    }

}