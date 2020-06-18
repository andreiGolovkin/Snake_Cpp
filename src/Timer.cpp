#include "Timer.h"

Timer::Timer(int _interval): interval(_interval){
    renew();
}

bool Timer::isTriggered(){
    return (start_time + interval) <= clock();
}

void Timer::renew(){
    start_time = clock();
}



void Timer::setInterval(int new_interval){
    interval = new_interval;
}
