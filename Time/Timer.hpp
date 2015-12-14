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

    /** Is timer paused. */
    bool paused;

    /** Time when timer was paused. */
    int64_t pauseTime;

public:
    Timer(Time& timeSource);
    
    void setTimeSource(Time& timeSource);
    virtual void reset();

    virtual int64_t timeTillElapsed(int64_t interval);
    virtual int64_t getElapsedTime();

    virtual bool hasElapsed(int64_t interval);
    virtual bool resetOnElapsed(int64_t interval);

    bool isPaused();
    virtual void pause();
    virtual void resume();
    
};

#endif
