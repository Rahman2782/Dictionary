#include "logger.h"
#include "event.h"

#include <cstring>

namespace seneca {
    Logger::Logger(size_t initialCapacity)
    : arr(std::make_unique<Event[]>(initialCapacity)), m_capacity(initialCapacity) {}

Logger::~Logger() {} //not needed with smart pointers

Logger::Logger(Logger&& src) noexcept 
    : arr(std::move(src.arr)), m_size(src.m_size) { //spend time understaning this
        src.m_size = 0;
        src.arr = nullptr;
    }

void Logger::addEvent(const Event& event) {
    if(m_size == m_capacity) {
        size_t newCapacity = m_capacity * 2;
        auto newArr = std::make_unique<Event[]>(newCapacity); 

        for(size_t i = 0; i < m_size; i++) {
            newArr[i] = std::move(arr[i]);
        }

        arr = std::move(newArr);
        m_capacity = newCapacity;
    }

    arr[m_size] = event;
    m_size++;
}  

}

