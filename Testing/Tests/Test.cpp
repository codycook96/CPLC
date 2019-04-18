#include <iostream>

#include "TestBench.h"



int main(int argc, char* argv[]){
    //Get commandline arguments
	std::vector<std::string> arguments;
	for(int i = 1; i < argc; i++){
		arguments.push_back(argv[i]);
	}

    //Test Flags
    bool runTestTypeCompare = false;


    //Set Test Flags
    for(unsigned int i = 0; i < arguments.size(); i++){
        if(arguments.at(i) == "TypeCompare" || arguments.at(i) == "All"){ runTestTypeCompare = true; }
    }

    TestBench* tb = new TestBench();

    //--------TYPE TESTING--------//
    //COMPARE
    if(runTestTypeCompare){ 
        //TestTypeCompare(*tb); 
    }
    



}