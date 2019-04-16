/*  Test Name:  Type Bounds Test
 *  
 *  Purpose:    Verify the type checking functionality: ensuring that
 *              types are properly created, strings return their proper 
 *              type ID's, and types are properly compared 
 *              
 *  Results:    See Results.txt for test results   
 */

#include <iostream>
#include <vector>
#include <fstream>

#include "Type.h"

const char* types_c[] = { 
"ANY", "ANY_DERIVED", "ANY_ELEMENTARY", "ANY_MAGNITUDE", "ANY_NUM", "ANY_INT", 
"SHORT_INT", "INT", "DINT", "LINT", "USINT", "UINT", "UDINT", "ULINT", 
"ANY_REAL", "REAL", "LREAL", "TIME", "ANY_BIT", "BOOL", "BYTE", "WORD", "DWORD",
"LWORD", "ANY_STRING", "STRING", "WSTRING", "ANY_DATE", "DATE", "DATE_AND_TIME",
"TIME_OF_DAY"
};

std::vector<std::string> types_s(types_c, std::end(types_c));

int main(){

    TypeHandler th;
    
    //std::ofstream file;
    //file.open("Test_TypeChecking_Results.txt");
    int a, b;

    for(unsigned int i = 0; i < types_s.size(); i++){
        std::cout << types_s.at(i) << " accepts: " << std::endl;

        for(unsigned int j = 0; j < types_s.size(); j++){
            
            a = th.getID(types_s.at(i));
            b = th.getID(types_s.at(j));

            if(th.accepts(a, b)){
                std::cout << types_s.at(j) << ", ";
            }

        }

        std::cout << std::endl << std::endl;

    }
}

