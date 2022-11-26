/*
Patrick Ging
Professor Zamanksy
Time.h
*/

#pragma once
#include <string>

class Time { 
    public:
        int h;
        int m;
};

int minutesSinceMidnight(Time time);

int minutesUntil(Time earlier, Time later);

Time addMinutes(Time time0, int min);

std::string time_to_string(Time time);