/*
	Patrick Ging
	Professor Zamansky
	Lab 10
	timeslot.cpp
*/

#include "time.h"
#include "movie.h"
#include "timeslot.h"

std::string getTimeSlot(TimeSlot ts) {
	std::string genre;

	switch(ts.movie.genre) {
	    case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;	
	}

	return ts.movie.title + " " + genre + "(" + ts.movie.duration + "min)" + " [starts at " + time_to_string(ts.startTime) + ", ends by " + time_to_string(addMinutes(ts.startTime, ts.movie.duration));
}
