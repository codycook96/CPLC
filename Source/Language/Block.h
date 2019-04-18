#ifndef BLOCK_H
#define BLOCK_H

#include <string>

//Block
class Block{
    protected:
        bool* tag;
        bool* wireIn;
        bool wireOut;
        
        //std::st_wireIng name;

    public:
        Block(bool* _tag, bool* _wireIn): tag(_tag), wireIn(_wireIn), wireOut(false){};
        //Block(std::st_wireIng n): name(n){}

        void exec(){ 
            wireOut = *(wireIn); 
        };

        bool* wire(){ 
            return &wireOut; 
        };
};

//Normally Open Contact
class NOC : public Block {
    private:

    public:
        NOC(bool* _tag, bool* _wireIn): Block(_tag, _wireIn){}

        void exec(){ 
            wireOut = *(tag) && *(wireIn); 
        } 
};

//Normally Closed Contact
class NCC : public Block {
    private:
        
    public:
        NCC(bool* _tag, bool* _wireIn): Block(_tag, _wireIn){}

        void exec(){ 
            wireOut = !(*(tag)) && *(wireIn);
        } 
};

//Output Coil
class OUT : public Block {
    private:

    public:
        OUT(bool* _tag, bool* _wireIn): Block(_tag, _wireIn){}

        void exec(){ 
            wireOut = *(wireIn);
            (*tag) = *(wireIn); 
        } 
};

//Negative Output Coil
class NOUT : public Block {
    private:

    public:
        OUT(bool* _tag, bool* _wireIn): Block(_tag, _wireIn){}

        void exec(){ 
            wireOut = *(wireIn);
            (*tag) = !(*(wireIn); 
        } 
};

//Set Coil
class SET : public Block {
    private:
        bool reset;

    public:
        SET(bool* _tag, bool* _wireIn): reset(false), Block(_tag, _wireIn){}

        void exec(){ 
            if(*(wireIn)){
                wireOut = *(wireIn);
                (*tag) = *(wireIn);
            }
            if(reset){
                wireOut = false;
                (*tag) = false;
            }
        } 

        bool* wireReset(){ return &reset; };
};

//Reset Coil
class RST : public Block {
    private:
        bool* reset;

    public:
        RST(bool* _tag, bool* _wireIn, bool* _reset): reset(_reset), Block(_t, _wireIn){}

        void exec(){ 
            wireOut = *(wireIn);
            (*tag) = *(wireIn); 
            (*reset) = *(wireIn);
        } 
};



#endif