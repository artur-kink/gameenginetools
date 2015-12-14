#include "Timer.hpp"

/**
 * Create a new timer.
 * @param timeSource Time class to use for timing.
 */
Timer::Timer(Time& timeSource):time(timeSource){
    reset();
}

/**
 * Set the Time class to use for timing.
 */
void Timer::setTimeSource(Time& timeSource){
    time = timeSource;
}

/**
 * Reset timer to start counting from current time.
 * If timer is paused, it is unpaused.
 */
void Timer::reset(){
    startTime = time.getTime();
    paused = false;
}

/**
 * Get amount of time elpased since last reset.
 */
int64_t Timer::getElapsedTime(){
    if(paused){
        return pauseTime - startTime;
    }
    return time.getTime() - startTime;
}

/**
 * Get amount of time till interval has elapsed.
 */
int64_t Timer::timeTillElapsed(int64_t interval){
    return interval - getElapsedTime();
}

/**
 * Check if timer has elapsed given interval.
 */
bool Timer::hasElapsed(int64_t interval){
    return getElapsedTime() >= interval;
}

/**
 * Reset timer if given interval has elapsed.
 * If timer is paused it is unpaused.
 * @return True if interval has elapsed.
 */
bool Timer::resetOnElapsed(int64_t interval){
    if(getElapsedTime() >= interval){
        reset();
        return true;
    }
    return false;
}

/**
 * Is timer paused.
 */
bool Timer::isPaused(){
    return paused;
}

/**
 * Pause timer.
 */
void Timer::pause(){
    if(!paused){
        pauseTime = time.getTime();
        paused = true;
    }
}

/**
 * Resume timer from pause.
 */
void Timer::resume(){
    if(paused){
        //Advance start time by the length of paused time
        startTime += (time.getTime() - pauseTime);
        paused = false;
    }
}
