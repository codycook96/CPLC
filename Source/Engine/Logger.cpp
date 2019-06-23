#include "Logger.h"
#include <iostream>
Logger::Logger(){

}

Logger::~Logger(){
    channels.clear();
}

void Logger::flush(){
    for(unsigned int i = 0; i < channels.size(); i++){
        *(channels.at(i)) << buffer.str();
    }
}



void Logger::addChannel(std::ostream* channel){
    channels.push_back(channel);
}

void Logger::clearChannels(){
    channels.clear();
}