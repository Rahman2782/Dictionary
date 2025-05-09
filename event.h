#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

#include <chrono>
#include <iostream>

namespace seneca {
    class Event {
        std::string m_name{};
        std::chrono::nanoseconds m_duration{};
    public:
        //public members
        Event();
        Event(const char* name, const std::chrono::nanoseconds& duration);
        ~Event();
    
        //friend helpers
        friend std::ostream& operator<<(std::ostream& os, Event& event); //"friend" only needs to be written in the declaration
    
    };
}


#endif //EVENT_H

//the Event class stores info about a single event that takes place during execution

//friend functions have access to priv data members 
//ostream& os is the output stream
    //passed by reference to avoid copying the whole object and modify the original