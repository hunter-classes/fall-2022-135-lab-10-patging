/*
	Patrick Ging
	Professor Zamanksy
	Lab 10
	main.cpp
*/
#include <iostream>

#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main() {
	//testing everything from A / B

	//initalizing the times

	Time t1 = {15,30}; // 1530 
	Time t2 = {19,30}; // 1930


    TimeSlot ts1 = {
        {"The Simpsons",DRAMA,120},
        {11,15}
    };


    TimeSlot ts2 = {
        {"Spongebob Squarepants",COMEDY,30},
        {11,0}
    };


	// min Since midnight
	std::cout << "There are " << minutesSinceMidnight(t1) << " minutes since midnight from " << time_to_string(t1) << std::endl;
	std::cout << "There are " << minutesSinceMidnight(t2) << " minutes since midnight from " << time_to_string(t2) << std::endl;

	// minutes until
	std::cout << "There are " << minutesUntil(t1, {12,0}) << " minutes until noon from " << time_to_string(t1) << std::endl;
	std::cout << "There are " << minutesUntil(t2, {12,0}) << " minutes until noon from " << time_to_string(t2) << std::endl;

	// getTimeSlot

	std::cout << getTimeSlot(ts1) << std::endl;
	std::cout << getTimeSlot(ts2) << std::endl;

	// Time Overlap
	std::cout << "Do the two above overlap?  0 false 1 true" << std::to_string(timeOverlap(ts1,ts2)) << std::endl;
 
	return 0;
}