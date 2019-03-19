#ifndef BLOCK_H
#define BLOCK_H

#include <string>

//Block
class Block{
    protected:
        bool* enable-in;
        bool enable-out;

    public:
        Block(bool* EN): enable-in(EN), enable-out(false){};

        void exec(){ 
            enable-out = *(enable-in); 
        };

        bool* wire(){ 
            return &enable-out; 
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