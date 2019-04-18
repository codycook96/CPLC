#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "Parser.h"
#include "Lexer.h"
#include "Linter.h"

class Assembler{
    private:
        Parser parser;
        Lexer lexer;
        Linter linter;
    
    public:
};

#endif