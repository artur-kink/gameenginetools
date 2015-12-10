#include "Timer.hpp"

Timer::Timer(Time& sourceTime):time(sourceTime){
    reset();
}

void Timer::reset(){
    startTime = time.getTime();
}

uint64_t Timer::getElapsedTime(){
    return time.getTime() - startTime;
}
