#include "Exception.h"

//Exception::Exception(std::string _msg, std::string _throwFile = "", int _throwLine = 0): msg(_msg), throwFile(""), throwFile(0){}

//Exception::Exception(std::string _msg, std::string _throwFile, int _throwLine): msg(_msg), throwFile(_throwFile), throwFile(_throwFile){}
Exception::Exception(std::string _msg): msg(_msg){}

const char* Exception::what() const throw (){
    return msg.c_str();
}