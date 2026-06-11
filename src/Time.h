#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    Time(int h, int m, int s);

    Time operator+(int sec) const;

    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif