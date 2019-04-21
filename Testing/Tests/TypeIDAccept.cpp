#include "TestList.h"

#include <vector>
#include <string>
#include <utility>

#include "Types.h"

//List of all types
std::vector<TYPE> typelist = {
    TYPE(TYPE_ANY),
    TYPE(TYPE_ANY_DERIVED),
    TYPE(TYPE_ANY_ELEMENTARY),
    TYPE(TYPE_ANY_MAGNITUDE),
    TYPE(TYPE_ANY_NUM),
    TYPE(TYPE_ANY_INT),
    TYPE(TYPE_SINT),
    TYPE(TYPE_INT),
    TYPE(TYPE_DINT),
    TYPE(TYPE_LINT),
    TYPE(TYPE_USINT),
    TYPE(TYPE_UINT),
    TYPE(TYPE_UDINT),
    TYPE(TYPE_ULINT),
    TYPE(TYPE_ANY_REAL),
    TYPE(TYPE_REAL),
    TYPE(TYPE_LREAL),
    TYPE(TYPE_TIME),
    TYPE(TYPE_ANY_BIT),
    TYPE(TYPE_BOOL),
    TYPE(TYPE_BYTE),
    TYPE(TYPE_WORD),
    TYPE(TYPE_DWORD),
    TYPE(TYPE_LWORD),
    TYPE(TYPE_ANY_STRING),
    TYPE(TYPE_STRING),
    TYPE(TYPE_WSTRING),
    TYPE(TYPE_ANY_DATE),
    TYPE(TYPE_DATE),
    TYPE(TYPE_DATE_AND_TIME),
    TYPE(TYPE_TIME_OF_DAY)
};

//Adjacency matrix for testing which types should accept which
std::vector<std::vector<int>> typecheck = {
    {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30},//0  TYPE_ANY
    {1},//1  TYPE_ANY_DERIVED
    {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30},//2  TYPE_ANY_ELEMENTARY
    {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17},//3  TYPE_ANY_MAGNITUDE
    {4,5,6,7,8,9,10,11,12,13,14,15,16},//4  TYPE_ANY_NUM
    {5,6,7,8,9,10,11,12,13},//5  TYPE_ANY_INT
    {6},//6  TYPE_SINT
    {7},//7  TYPE_INT
    {8},//8  TYPE_DINT
    {9},//9  TYPE_LINT
    {10},//10  TYPE_USINT
    {11},//11 TYPE_UINT
    {12},//12 TYPE_UDINT
    {13},//13 TYPE_ULINT
    {14,15,16},//14 TYPE_ANY_REAL
    {15},//15 TYPE_REAL
    {16},//16 TYPE_LREAL
    {17},//17 TYPE_TIME
    {18,19,20,21,22,23},//18 TYPE_ANY_BIT
    {19},//19 TYPE_BOOL
    {20},//20 TYPE_BYTE
    {21},//21 TYPE_WORD
    {22},//22 TYPE_DWORD
    {23},//23 TYPE_LWORD
    {24,25,26},//24 TYPE_ANY_STRING
    {25},//25 TYPE_STRING
    {26},//26 TYPE_WSTRING
    {27,28,29,30},//27 TYPE_ANY_DATE
    {28},//28 TYPE_DATE
    {29},//29 TYPE_DATE_AND_TIME
    {30} //30 TYPE_TIME_OF_DAY
};

void Testing::TypeIDAccept(TestBench& tb){
    Test& t = *(new Test("TypeIDAccept"));    

    //Test information
    t.info << "Checking that parent data type ID's accept child type ID's" << std::endl;



    //Add Cases
    for(int i = 0; i < (int) typelist.size(); i++){
        t.addCase(
            [&, i] () -> bool {
                bool shouldAccept = false;
                bool passed = true;
                t.report << "+=====================================+" << std::endl;
                for(unsigned int j = 0; j < typelist.size(); j++){
                    shouldAccept = false;
                    for(unsigned int k = 0; k < typecheck.at(i).size(); k++){
                        if(j == (unsigned int) typecheck.at(i).at(k)){
                            shouldAccept = true;
                        }
                    }

                    t.report << "Type " << typelist.at(i).getLabel();
                    if(shouldAccept){
                    t.report << " should ";
                    }
                    else{
                    t.report << " shouldn't ";
                    }
                    t.report << "accept type " << typelist.at(j).getLabel() << ": ";

                    if(typelist.at(i).accepts(typelist.at(j)) == shouldAccept){
                        t.report << "Passed" << std::endl;
                    }
                    else{
                        passed = false;
                        t.report << "Failed" << std::endl;
                    }
                }
                
                return passed;
            }
        );
    }
    /*
    t.addCase(
        [&] () -> bool { 
            for(unsigned int i = 0; i < typelist.size(); i++){
                for(unsigned int j = 0; j < typelist.size(); j++){
                    t.report << typelist.at(i).getLabel() << " accepts " << typelist.at(j).getLabel() << ": ";
                    t.report << typelist.at(i).accepts(typelist.at(j)) << std::endl;
                }
                t.report << "+==========================================+" << std::endl;
            }
            //t.report << "Testing acceptance of "  << std::endl; 

            return true; 
        }
    );
    */
    tb.addTest(&t, t.getName());
}