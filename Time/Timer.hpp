#ifndef _TIMER_HPP
#define _TIMER_HPP

#include "Time.hpp"

class Timer{
private:
    Time& time; 
    uint64_t startTime;
public:
    Timer(Time& sourceTime);
    
    void reset();
    virtual uint64_t getElapsedTime();
};

#endif
