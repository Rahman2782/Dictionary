#ifndef SENECA_LOGGER_H
#define SENECA_LOGGER_H

#include "event.h"
#include <memory>

namespace seneca {

    class Logger {
        Logger(const Logger& src) {} //copy disabled
        std::unique_ptr<Event[]> arr; 
        size_t m_size{0}; //actual number of elements in array
        size_t m_capacity{0}; //currenty allocated space
    
    public:
        Logger(size_t initialCapacity = 10);
        ~Logger();
        Logger(Logger&& src) noexcept;
        void addEvent(const Event& event);
        friend std::ostream& operator<<(std::ostream& os, Logger& l) {
            for(int i = 0; i < l.m_size; i++) {
                os << l.arr.get()[i] << std::endl; //modified for smart pointer usage
            }
            return os;
        }
    };
}

#endif //LOGGER_H




//to disable copy operations, make the copy constructor private w/ no implementation
    //why disable copying (below)


//modified assignment to utilize smart pointers