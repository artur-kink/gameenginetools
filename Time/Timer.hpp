#ifndef _TIMER_HPP
#define _TIMER_HPP

#include "Time.hpp"

/**
 * Basic timer, keeps track of elapsed time since last reset.
 */
class Timer{
protected:
    /** Time source for timing. */
    Time& time; 

    /** Reference time to start of timer. */
    int64_t startTime;
public:
    Timer(Time& timeSource);
    
    void setTimeSource(Time& timeSource);
    void reset();

    int64_t timeTillElapsed(int64_t interval);
    virtual int64_t getElapsedTime();

    bool hasElapsed(int64_t interval);
    bool resetOnElapsed(int64_t interval);
};

#endif
