#ifndef LOGGER_H
#define LOGGER_H

#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

class Logger{
    private:
        std::ostringstream buffer;
        std::vector<std::ostream*> channels;
        std::mutex inputMutex;
		
    public:
        Logger();
        ~Logger();
        
        void flush();
        void addChannel(std::ostream* channel);
        void clearChannels();

    	//Stream Input
		template<typename T>
		Logger& operator<< (const T& t){
			//Only one thread writes input at a time
			inputMutex.lock();
			
            buffer << t;

			inputMutex.unlock();
			return *this;
		}

		//Stream Input for ostream manip type objects
		Logger& operator<< (std::ostream&(*pManip)(std::ostream&)){
			//Only one thread writes input at a time
			inputMutex.lock();
			
			//Send output to enabled streams
			buffer << (*pManip);
			
			inputMutex.unlock();
			return *this;
		}

};

#endif