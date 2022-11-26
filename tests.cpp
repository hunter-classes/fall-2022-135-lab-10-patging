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
#include "timeslot.h"

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


TEST_CASE("getTimeSlot") {

    TimeSlot ts1 = {
        {"Test",DRAMA,120},
        {12,0}
    };


    TimeSlot ts2 = {
        {"Test2",COMEDY,0},
        {12,0}
    };


    TimeSlot ts3 = {
        {"Test3",THRILLER,1440},
        {12,0}
    };

    CHECK(getTimeSlot(ts1) == "Test DRAMA (120 min) [starts at 12:00, ends by 14:00]");
    CHECK(getTimeSlot(ts2) == "Test2 COMEDY (0 min) [starts at 12:00, ends by 12:00]");
    CHECK(getTimeSlot(ts3) == "Test3 THRILLER (1440 min) [starts at 12:00, ends by 12:00]");
}


TEST_CASE("Time Overlap") {
    TimeSlot ts1 = {
        {"Test",DRAMA,120},
        {12,0}
    }; // starts at 12:00, ends at 14:00


    TimeSlot ts2 = {
        {"Test2",COMEDY,90},
        {13,0} 
    }; // starts at 13:00, ends at 14:30


    TimeSlot ts3 = {
        {"Test3",THRILLER,300},
        {12,0} 
    }; // starts at 12:00 ends at 17:00

    TimeSlot ts4 = {
        {"Test3",THRILLER,300},
        {1,0} 
    }; // 01:00 to 6:00

    CHECK(timeOverlap(ts1,ts2)); 
    CHECK(timeOverlap(ts2, ts1));
    CHECK(timeOverlap(ts3,ts2));
    CHECK(timeOverlap(ts3,ts1));

    CHECK(! timeOverlap(ts4,ts2));
    CHECK(! timeOverlap(ts1, ts4));
}

TEST_CASE("schedule After") {
    TimeSlot ts1 = {
        {"Test",DRAMA,120},
        {12,0}
    }; // starts at 12:00, ends at 14:00


    TimeSlot ts2 = {
        {"Test2",COMEDY,90},
        {13,0} 
    }; // starts at 13:00, ends at 14:30


    TimeSlot ts3 = {
        {"Test3",THRILLER,300},
        {12,0} 
    }; // starts at 12:00 ends at 17:00

    TimeSlot ts4 = {
        {"Test3",THRILLER,300},
        {1,0} 
    }; // 01:00 to 6:00

    Movie mv = {"Test",ACTION,100}; // generic it doesn't really matter

    CHECK(scheduleAfter(ts1,mv).startTime.h == 14);
    CHECK(scheduleAfter(ts1,mv).startTime.m == 0);
    
    CHECK(scheduleAfter(ts2,mv).startTime.h == 14);
    CHECK(scheduleAfter(ts2,mv).startTime.h == 30);
    
    CHECK(scheduleAfter(ts3,mv).startTime.h == 17);
    CHECK(scheduleAfter(ts3,mv).startTime.h == 0);
    
    CHECK(scheduleAfter(ts4,mv).startTime.h == 6);
    CHECK(scheduleAfter(ts4,mv).startTime.h == 0);
}