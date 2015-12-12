#ifndef _CARRYTIMER_HPP
#define _CARRYTIMER_HPP

#include "Timer.hpp"

/**
 * Timer that can carry over extra time on elapsed intervals.
 */
class CarryTimer:public Timer{
protected:

    /** Amount of time carried over. */
    int64_t carryTime;
public:
    CarryTimer(Time& timeSource);
  
    void addCarry(int64_t carry);
    void subtractCarry(int64_t carry);
    void setCarry(int64_t carry);
    int64_t getCarry();

    void resetCarry();

    virtual int64_t getElapsedTime();

    virtual bool resetOnElapsed(int64_t interval);  
};

#endif
