/*
	Patrick Ging
	Professor Zamansky
	Lab 10
	timeslot.cpp
*/

#include <iostream>
#include <string>

#include "time.h"
#include "movie.h"
#include "timeslot.h"

std::string getTimeSlot(TimeSlot ts) {
	/*
		Return a string describing timeslot
	*/
	std::string genre;

	switch(ts.movie.genre) {
	    case ACTION   : genre = "ACTION"; break;
        case COMEDY   : genre = "COMEDY"; break;
        case DRAMA    : genre = "DRAMA";  break;
        case ROMANCE  : genre = "ROMANCE"; break;
        case THRILLER : genre = "THRILLER"; break;	
	}

	return ts.movie.title + " " + genre + " (" + std::to_string(ts.movie.duration) + " min)" + " [starts at " + time_to_string(ts.startTime) + ", ends by " + time_to_string(addMinutes(ts.startTime, ts.movie.duration)) + "]";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
	/*
		Returns a timeslot for a movie that will come after 
		timeslot ts
	*/

	return {
		nextMovie,
		addMinutes(ts.startTime,ts.movie.duration)
	}; // returning as a literal

}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
	/*
		Will return whether or not two timeslots overlap
	
		If ts1's end duration is after the start they overlap
	*/

	return minutesUntil(ts1.startTime, ts2.startTime) < ts1.movie.duration ||
		minutesUntil(ts2.startTime, ts1.startTime) < ts2.movie.duration; 
	// this way it's agnostic to which one starts first
}

/*
int main() {


    TimeSlot ts1 = {
        {"Test",DRAMA,120},
        {12,0}
    };

    std::cout << getTimeSlot(ts1);

	return 0;
}

*/