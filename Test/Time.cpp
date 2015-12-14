#include "../GET_Time.hpp"
#include <assert.h>

class TestTime:public Time{
public:
    uint64_t timeValue;
    TestTime(){
        timeValue = 0;
    }

    void setTime(uint64_t t){
        timeValue = t;
    }
    
    virtual uint64_t getTime(){
        return timeValue;
    }

};


int main(int argc, char** argv){

    TestTime time;
    time.setTime(0);
    Timer timer(time);
    
    //Test initial values with unchanged time
    assert(timer.getElapsedTime() == 0);
    assert(timer.hasElapsed(1) == false);
    assert(timer.resetOnElapsed(1) == false);
    assert(timer.timeTillElapsed(1) == 1);

    //Test with time at 1
    time.setTime(1);
    assert(timer.getElapsedTime() == 1);
    assert(timer.hasElapsed(1));
    assert(timer.timeTillElapsed(1) == 0);
    assert(timer.resetOnElapsed(1));

    //Test time at 1 with reset at time 1
    assert(timer.getElapsedTime() == 0);
    assert(timer.hasElapsed(1) == false);
    assert(timer.resetOnElapsed(1) == false);
    assert(timer.timeTillElapsed(1) == 1);

    //Test pausing
    assert(timer.isPaused() == false);
    timer.pause();
    assert(timer.isPaused());
    time.setTime(5);
    timer.resume();
    assert(timer.getElapsedTime() == 0);
    time.setTime(6);
    assert(timer.getElapsedTime() == 1);
    timer.pause();
    time.setTime(7);
    assert(timer.getElapsedTime() == 1);
    timer.resume();
    assert(timer.getElapsedTime() == 1);
    
    //Test resetOnElapsed with pause
    time.setTime(8);
    assert(timer.getElapsedTime() == 2);
    timer.pause();
    assert(timer.resetOnElapsed(1) == true);
    assert(timer.isPaused() == false);
    assert(timer.getElapsedTime() == 0);



    //CarryTimer tests
    time.setTime(0);
    CarryTimer carryTimer(time);
    assert(carryTimer.getElapsedTime() == 0);
    assert(carryTimer.hasElapsed(1) == false);
    assert(carryTimer.resetOnElapsed(1) == false);
    assert(carryTimer.timeTillElapsed(1) == 1);
    assert(carryTimer.getCarry() == 0);

    time.setTime(1);
    assert(carryTimer.getElapsedTime() == 1);
    assert(carryTimer.hasElapsed(1) == true);
    assert(carryTimer.timeTillElapsed(1) == 0);
    assert(carryTimer.resetOnElapsed(0));
    //Reset on elapsed of 0 should carry 1
    assert(carryTimer.getCarry() == 1);
    assert(carryTimer.hasElapsed(1));
    assert(carryTimer.getElapsedTime() == 1);
    //Reset on elapsed of 1 should use up carry of 1
    assert(carryTimer.resetOnElapsed(1));
    assert(carryTimer.getCarry() == 0);

    //Reset timer to 0
    time.setTime(0);
    carryTimer.reset();

    //At time 5 we should be able to resetElapsed 5 times
    time.setTime(5);
    assert(carryTimer.getCarry() == 0);
    assert(carryTimer.getElapsedTime() == 5);
    assert(carryTimer.resetOnElapsed(1));
    assert(carryTimer.getCarry() == 4);
    assert(carryTimer.getElapsedTime() == 4);
    assert(carryTimer.resetOnElapsed(1));
    assert(carryTimer.getCarry() == 3);
    assert(carryTimer.getElapsedTime() == 3);
    assert(carryTimer.resetOnElapsed(1));
    assert(carryTimer.getCarry() == 2);
    assert(carryTimer.getElapsedTime() == 2);
    assert(carryTimer.resetOnElapsed(1));
    assert(carryTimer.getCarry() == 1);
    assert(carryTimer.getElapsedTime() == 1);
    assert(carryTimer.resetOnElapsed(1));
    assert(carryTimer.getCarry() == 0);
    assert(carryTimer.getElapsedTime() == 0);
    assert(carryTimer.resetOnElapsed(1) == false);

    time.setTime(6);
    assert(carryTimer.getCarry() == 0);
    assert(carryTimer.getElapsedTime() == 1);
    assert(carryTimer.resetOnElapsed(0));
    //Reset on elapsed 0 should carry 1
    assert(carryTimer.getCarry() == 1);
    assert(carryTimer.getElapsedTime() == 1);
    
    //Increasing time by 1 and with 1 carry
    time.setTime(7);
    assert(carryTimer.getElapsedTime() == 2);
    assert(carryTimer.getCarry() == 1);
    assert(carryTimer.resetOnElapsed(1));
    //Reset on elapsed 1 should have used up elapsed time,
    //but kept carry at 1
    assert(carryTimer.getCarry() == 1);
    assert(carryTimer.getElapsedTime() == 1);

    //Test pausing with CarryTimer
    assert(carryTimer.isPaused() == false);
    carryTimer.pause();
    assert(carryTimer.isPaused());
    assert(carryTimer.getElapsedTime() == 1);
    time.setTime(8);
    assert(carryTimer.getElapsedTime() == 1);
    carryTimer.resume();
    assert(carryTimer.getElapsedTime() == 1);
    
    //Test paused resetOnElapsed with CarryTimer
    carryTimer.pause();
    time.setTime(9);
    assert(carryTimer.resetOnElapsed(1)); 
    assert(carryTimer.isPaused() == false);
    assert(carryTimer.getCarry() == 0);
    assert(carryTimer.getElapsedTime() == 0);
    
}
