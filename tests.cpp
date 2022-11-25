/*
    Patrick Ging
    Professor Zamanksy
    Lab 10
    tests.cpp


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>

#include "doctest.h"
#include "time.h"

TEST_CASE("Testing test class and related functions") {
    Time t1 = {12, 0}; // 12:00
    Time t2 = {16, 0}; // 16:00

    //testing initialization
    CHECK(t1.h == 12);
    CHECK(t1.m == 0);
    CHECK(t2.h == 16);
    CHECK(t2.m == 0);

    // minutes since midnight
    CHECK(minutesSinceMidnight(t1) == 720);
    CHECK(minutesSinceMidnight(t2) == 960);

    // minutes until
    CHECK(minutesUntil(t1, t2) == 240);
    CHECK(minutesUntil(t2, t1) == 240);

}
*/