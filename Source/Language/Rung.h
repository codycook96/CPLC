#ifndef RUNG_H
#define RUNG_H

#include <vector>

#include "Block.h"

class Rung{
    private:
        std::vector<Block*> blocks;
        bool rail;
        bool* endWire;
    public:
        Rung(): rail(true) { 
            endWire = &rail; 
        };

        void exec(){
            for(unsigned int i = 0; i < blocks.size(); i++)
                blocks.at(i)->exec();
        }

        
        //Creation of blocks goes in Page.h
};

#endif