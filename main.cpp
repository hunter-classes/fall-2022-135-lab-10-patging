/*
	Patrick Ging
	Professor Zamanksy
	Lab 10
	main.cpp
*/
#include <iostream>

#include "time.h"


int main() {
	//testing everything from A / B

	//initalizing the times

	Time t1 = {15,30}; // 1530 
	Time t2 = {19,30}; // 1930

	// min Since midnight
	std::cout << "There are " << minutesSinceMidnight(t1) << " minutes since midnight from " << time_to_string(t1) << std::endl;
	std::cout << "There are " << minutesSinceMidnight(t2) << " minutes since midnight from " << time_to_string(t2) << std::endl;

	// minutes until
	std::cout << "There are " << minutesUntil(t1, {12,0}) << " minutes until noon from " << time_to_string(t1) << std::endl;
	std::cout << "There are " << minutesUntil(t2, {12,0}) << " minutes until noon from " << time_to_string(t2) << std::endl;


	return 0;
}