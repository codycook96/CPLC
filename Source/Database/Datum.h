#ifndef DATUM_H
#define DATUM_H

#include <cstdint>
#include <cstring>
#include <iostream>
#include <typeinfo>

struct DATUM{
    unsigned char size;
    unsigned char* datum;

    //DATUM Default Constructor
    DATUM();

    //DATUM Defalt Destructor
    ~DATUM();

    //DATUM Templated Constructor
    template <typename T>
    DATUM(T v){
        size = sizeof(v);
        datum = new unsigned char[size];
        memcpy(datum, (unsigned char*)&v, sizeof(v));
    }

    //DATUM Copy Constructor
    DATUM(const DATUM& d);

    //DATUM Assignment Operator
    DATUM& operator=(const DATUM& d);

    /*
    //DATUM Template Assignment Operator
    template <template T>
    DATUM& operator=(const T& v){
        *((T*) datum) = v;
        return *this;
    }
    */

    //DATUM Template Setter
    template <typename T>
    void set(T v){
        *((T*) datum) = v;
    }

    template <typename T>
    T& get(){
        //std::cout << "datum get: " << typeid(T).name() << std::endl;
        return *((T*) datum);
    }
    
};

#endif