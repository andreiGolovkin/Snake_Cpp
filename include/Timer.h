#ifndef TIMER_H
#define TIMER_H

#include <time.h>

#include <iostream>

using namespace std;


class Timer{
    public:
        Timer(int _interval);

        bool isTriggered();
        void renew();

        void setInterval(int new_interval);
    protected:

    private:
        time_t interval;
        time_t start_time;
};

#endif // TIMER_H
