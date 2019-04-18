#include "Datum.h"

//DATUM Default Constructor
DATUM::DATUM(){
    size = 1;
    datum = new unsigned char[size];
}

//DATUM Default Destructor
DATUM::~DATUM(){
    //std::cout << "DELETING SOMETHING" << std::endl;
    delete datum;
}

//DATUM Copy Constructor
DATUM::DATUM(const DATUM& d){
    size = d.size;
    datum = new unsigned char[size];
    memcpy(datum, d.datum, size);
}

//DATUM Assignemnt Operator
DATUM& DATUM::operator=(const DATUM& d){
    size = d.size;
    datum = new unsigned char[size];
    memcpy(datum, d.datum, size);
    return *this;
}