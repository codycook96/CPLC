#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>
#include <sstream>

class Exception: virtual public std::exception {
    protected:
        std::string msg;
        std::string throwFile;
        int throwLine;

    public:
        //Exception Virtual Destructor
        virtual ~Exception() throw () {}

        //Exception Default Constructor
        explicit Exception();

        //Exception STL String Constructor
        explicit Exception(std::string _msg, std::string _throwFile = "", int _throwLine = -1);

        //Overloading std::exception what()
        virtual const char* what() const throw ();

        //Exception to string
        const std::string read() const;
};

#endif