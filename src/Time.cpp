#include "Time.h"

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s)
    : hours(h), minutes(m), seconds(s) {}

Time Time::operator+(int sec) const
{
    Time result = *this;

    result.seconds += sec;

    result.minutes += result.seconds / 60;
    result.seconds %= 60;

    result.hours += result.minutes / 60;
    result.minutes %= 60;

    result.hours %= 24;

    return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
       << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
       << (t.seconds < 10 ? "0" : "") << t.seconds;

    return os;
}