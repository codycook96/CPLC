#ifndef DATA_H
#define DATA_H

#include <cstdint>
#include <cstring>
#include <iostream>
#include <typeinfo>

struct DATA{
    unsigned char size;
    unsigned char* data;

    DATA(){
        size = 1;
        data = new unsigned char[size];
    }

    template <typename T>
    DATA(T v){
        size = sizeof(v);
        data = new unsigned char[size];
        memcpy(data, (unsigned char*)&v, sizeof(v));
    }

    ~DATA(){
        //std::cout << "DELETING SOMETHING" << std::endl;
        //delete data;
    }

    DATA(const DATA& d){
        size = d.size;
        data = new unsigned char[size];
        memcpy(data, d.data, size);
    }

    DATA& operator=(const DATA& d){
        size = d.size;
        data = new unsigned char[size];
        memcpy(data, d.data, size);
        return *this;
    }

    template <typename T>
    void set(T v){
        *((T*) data) = v;
    }

    template <typename T>
    T& get(){
        //std::cout << "data get: " << typeid(T).name() << std::endl;
        return *((T*) data);
    }
    
};

#endif