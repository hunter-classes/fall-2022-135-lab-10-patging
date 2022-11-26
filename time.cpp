/*
Patrick Ging
Professor Zamanksy
time.cpp
*/
#include <cmath>

#include "time.h"

int minutesSinceMidnight(Time time) {
    /*
        Returns the minutes SINCE midnight from time
    */
    return 60 * time.h + time.m;
}

int minutesUntil(Time earlier, Time later) {
    /*
        Returns minutes from earlier to later
        by subtracting minutes in later from minutes
        in earlier and applying absolute func
    */
    return std::abs((60 * later.h + later.m) - (60 * earlier.h + earlier.m));
}

Time addMinutes(Time time0, int min) {
    /*
        Adds minutes to time0 and returns it
    */
   return {
    (time0.h + (int) std::floor((time0.h + min) / 60)) % 24, // add over whole hours & keeping it sub-24 hr
    time0.m + min % 60 // if any time is added over we leave mod 
   }; // returning as a class
}

// for debugging and main.cpp purposes only
std::string time_to_string(Time time) {
    //turns time into hour::min format 24 mode
    return std::to_string(time.h) + ":" + std::to_string(time.m);
}