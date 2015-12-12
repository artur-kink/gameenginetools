#include "CarryTimer.hpp"

CarryTimer::CarryTimer(Time& timeSource):Timer(timeSource){
    carryTime = 0;
}

void CarryTimer::resetCarry(){
    carryTime = 0;
}

void CarryTimer::setCarry(int64_t carry){
    carryTime = carry;
}

int64_t CarryTimer::getCarry(){
    return carryTime;
}

void CarryTimer::addCarry(int64_t carry){
    carryTime += carry;
}

void CarryTimer::subtractCarry(int64_t carry){
    carryTime -= carry;
}

int64_t CarryTimer::getElapsedTime(){
    return time.getTime() - startTime + carryTime; 
}

/**
 * Reset timer if given interval has elapsed.
 * Carry over any extra time that has elapsed past the interval.
 */
bool CarryTimer::resetOnElapsed(int64_t interval){
    int64_t elapsedNonCarry = Timer::getElapsedTime();
    if(elapsedNonCarry >= interval){
        //Carry over extra time
        addCarry(elapsedNonCarry - interval);
        reset();
        return true;
    }else if(elapsedNonCarry + carryTime >= interval){
        int64_t carryUsed = interval - elapsedNonCarry;
        subtractCarry(carryUsed);
        reset();
        return true;
    }
    return false;    
} 
