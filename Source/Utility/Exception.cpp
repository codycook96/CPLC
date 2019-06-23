#include "Exception.h"

Exception::Exception(): msg("Default Exception"){}

Exception::Exception(std::string _msg, std::string _throwFile, int _throwLine): msg(_msg), throwFile(_throwFile), throwLine(_throwLine){}

const char* Exception::what() const throw (){
    return read().c_str();
}

const std::string Exception::read() const{
    std::stringstream ss;
    if(throwLine < 0 or throwFile == ""){
        ss << msg << std::endl;
    }
    else{
        ss << msg << "/t" << "[file: " << throwFile << ", on line: " << throwLine << "]" << std::endl;
    }
    return ss.str();
}