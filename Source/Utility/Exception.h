#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

class Exception: virtual public std::exception {
    protected:
        std::string msg;
        std::string throwFile;
        int throwLine;

    public:
        //Exception Virtual Destructor
        virtual ~Exception() throw () {}

        //Exception Default Constructor
        //explicit Exception();

        //Exception CString Constructor
        //explicit Exception(const char* _msg);

        //Exception STL String Constructor
        //explicit Exception(std::string _msg = "Default Exception", std::string _throwFile = "", int _throwLine = 0);
        explicit Exception(std::string _msg);

        //Overloading std::exception what()
        virtual const char* what() const throw ();

        
};

#endif