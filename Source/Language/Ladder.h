#ifndef LADDER_H
#define LADDER_H

#include <vector>
#include <string>
#include <map>
#include <iterator>

class Ladder{
    private:
        std::map<std::string, bool> digitalTags; 

    public:
        void addDigitalTag(std::string t){
            if(digitalTags.find(t) == digitalTags.end())
                digitalTags.insert(std::make_pair(t, false));
        }
        void setDigitalTag(std::string t, bool b){
            digitalTags[t] = b;
        }
        bool getDigitalTag(std::string t){
            return digitalTags[t];
        }

};


#endif