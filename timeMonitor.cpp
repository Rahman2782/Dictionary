#include "timeMonitor.h"

#define _CRT_SECURE_NO_WARNINGS

namespace seneca {
    
    void TimeMonitor::startEvent(const char* name) {
        strncpy_s(m_eventName, name, 100);
        m_eventName[99] = '\0';
    
        m_startTime = std::chrono::steady_clock::now();
    }
    
    Event TimeMonitor::stopEvent() {
        m_endTime = std::chrono::steady_clock::now();
    
        auto duration = m_endTime - m_startTime;
    
        return Event(m_eventName, duration); //returning an instance of Event type
    }

}




//strncpy is a safer version of strcpy, it will copy 99 chars from name to m_eventName
    //only 99 chars because last element is the null terminator
        // '\0' marks the end  of the c string 


//NOTES ON CHRONO TO BE ADDED (time points, durations)
