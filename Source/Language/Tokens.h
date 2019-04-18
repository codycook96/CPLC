#ifndef TOKENS_H
#define TOKENS_H

#include <string>
#include <vector>

#include "Type.h"
#include "Delimiter.h"

enum ParameterType{
    PAR_TAG = 0,   //Tag
    PAR_LITERAL = 1    //Literal
};



struct Data{
    DataType dt;
    
};

enum TokenType{
    TOK_RUNG = 0,   //Rung
    TOK_RAIL = 1,   //Rail
    TOK_RAIL_CONNECTOR = 2,   //Rail Connector
    TOK_DOWN_CONNECTOR = 3,   //Down Connector
    TOK_UP_CONNECTOR = 4,   //Up Connector
    TOK_LOGIC_BLOCK = 5,   //Logic Block
    TOK_COIL_BLOCK = 6,   //Coil Block
    TOK_FUNCTION_BLOCK = 7,   //Function Block
    TOK_COMMENT_BLOCK = 8    //Comment Block
};

struct Token{
    TokenType tt;


};


#endif