/*
    Patrick Ging
    Professor Zamanksy
    Lab 10
    tests.cpp

*/
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

TEST_CASE("AddingMinutes") {
    Time t1 = {12,0}; // noon

    // perhaps a better way to do it, but g++ was demolishing me
    CHECK(addMinutes(t1, 60).h == 13);
    CHECK(addMinutes(t1, 61).m == 1);
    CHECK(addMinutes(t1,1440).h == 12);
    CHECK(addMinutes(t1,1440).m == 0);
}