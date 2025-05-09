#ifndef SENECA_SETTINGS_H
#define SENECA_SETTINGS_H

#include <string>

namespace seneca {

    struct Settings {
        //public members
        bool m_show_all{};
        bool m_verbose{};
        std::string m_time_units = "nanoseconds"; 
    };
    
    extern Settings g_settings; //extern declaration
}



#endif //SETTINGS_H


//m_show_all prints all definitions for a word
//m_verbose prints the part-of-speech of the word (if true)
//m_time_units stores the stores the time units to be used when printing operations