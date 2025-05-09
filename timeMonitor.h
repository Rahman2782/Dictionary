#ifndef SENECA_TIMEMONITOR_H
#define SENECA_TIMEMONITOR_H

#include <chrono>
#include <cstring>
#include "event.h"

namespace seneca {

    class TimeMonitor {
        char m_eventName[100]{};
        std::chrono::steady_clock::time_point m_startTime;
        std::chrono::steady_clock::time_point m_endTime;
    public:
        void startEvent(const char* name);
        Event stopEvent();
    };
}


#endif //TIMEMONITOR_H

