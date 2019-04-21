#include <iostream>
#include <string>

#include "TestBench.h"
#include "TestList.h"


int main(int argc, char* argv[]){
    //Get commandline arguments
	std::vector<std::string> arguments;
	for(int i = 1; i < argc; i++){
		arguments.push_back(argv[i]);
	}

    TestBench* tb = new TestBench();
    tb->setPath("Results/");

    //Call Tests
    Testing::TypeEquality(*tb);
    Testing::TypeComparison(*tb);
    //Testing::TypeCasting(*tb);
    Testing::TypeIDAccept(*tb);
    //Testing::TypeSetGet(*tb);


    if(arguments.size() <= 0){
        std::cout << "Test List: " << std::endl;

        std::vector<std::string> list;
        list = tb->testList();
        for(unsigned int i = 0; i < list.size(); i++){
            std::cout << i + 1 << ": " << list.at(i) << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Enter test numers (separated by spaces): " << std::endl;

        std::string line = "";
        std::string input = "";
        int testNum = 0;

        std::getline(std::cin, line);
        std::istringstream ss(line);

        while(ss >> input){
            std::string::const_iterator it = input.begin();
            while (it != input.end()){
                if(!std::isdigit(*it)){
                    std::cout << "Error input " << input << " not a number! Quitting..." << std::endl;
                    return 0;
                }
                it++;
            }
            testNum = std::stoi(input);
            testNum = testNum - 1;
            if(testNum < 0 || testNum >= (int) list.size()){
                std::cout << "Error number " << testNum << " does not correspond to a test! Quitting..." << std::endl;
                return 0;
            }

            arguments.push_back(list.at(testNum));
        }
    }

    tb->test(arguments);
}