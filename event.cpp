#include "event.h"
#include "settings.h"

#include <iomanip>

namespace seneca {

    static int eventCounter{0};

    Event::Event() {}

    Event::Event(const char* name, const std::chrono::nanoseconds& duration)
        : m_name(name), m_duration(duration) {}
    
    Event::~Event() {}

   /*
       std::ostream& operator<<(std::ostream& os, Event& event) {
        static int count = 0;
        os << std::right << std::setw(2) << count << ": " 
        << std::right << std::setw(40) << event.m_name << " -> "
        << std::right << std::setw(11) << event.m_duration << " "
        << "Nanoseconds" << std::endl; //double check 'TIME_UNITS'
        return os;
    }
   */ 

    
    std::ostream& operator<<(std::ostream& os, Event& event) {
        eventCounter++;
        os << std::right << std::setw(2) << eventCounter << ": "
           << std::right << std::setw(40) << event.m_name << " -> ";

        if (g_settings.m_time_units == "seconds") {
            os << std::right << std::setw(2) << std::chrono::duration_cast<std::chrono::seconds>(event.m_duration).count() << " seconds";
        } else if (g_settings.m_time_units == "milliseconds") {
            os << std::right << std::setw(5) << std::chrono::duration_cast<std::chrono::milliseconds>(event.m_duration).count() << " milliseconds";
        } else if (g_settings.m_time_units == "microseconds") {
            os << std::right << std::setw(8) << std::chrono::duration_cast<std::chrono::microseconds>(event.m_duration).count() << " microseconds";
        } else { //default to nanoseconds
            os << std::right << std::setw(11) << event.m_duration.count() << " nanoseconds";
        }
        return os;
    }

}


