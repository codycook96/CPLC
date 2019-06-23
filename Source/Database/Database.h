#ifndef DATABASE_H
#define DATABASE_H

#include <utility>  //std::pair 

#include "Types.h"
#include "Datum.h"

#include "Exception.h"

class Database{
    private:
        std::unordered_map<std::string, std::pair<TYPE, ANY*>> data;
    public:
        void add(TYPE t, std::string varName);

        template <typename T> 
        T link(std::string varName){
            T out = dynamic_cast<T>(data.at(varName).first);
            if(out == nullptr){
                std::cout << "Fail" << std::endl;
                throw "Some Error";
                return out;
            }
            //std::cout << "Good" << std::endl;
            return out;
        }

        TYPE getType(std::string varName);
};

#endif