#Patrick Ging Makefile

main: main.o timeslot.o time.o movie.o
	g++ -o main -std=c++11 main.o  timeslot.o time.o movie.o

tests: tests.o time.o timeslot.o
	g++ -o tests -std=c++11 tests.o time.o timeslot.o

clean:
	rm a.exe a.out main tests *.o

#.o files
main.o: main.cpp time.h movie.h timeslot.h
	g++ -c -std=c++11 main.cpp time.cpp movie.cpp timeslot.cpp 

movie.o: movie.h time.h movie.cpp time.cpp
	g++ -c -std=c++11 movie.cpp time.cpp

timeslot.o: timeslot.h movie.h time.h movie.cpp time.cpp timeslot.cpp
	g++ -c -std=c++11 movie.cpp time.cpp timeslot.cpp

time.o: time.h time.cpp
	g++ -c -std=c++11 time.cpp

tests.o: time.cpp doctest.h time.h
	g++ -c -std=c++11 tests.cpp time.cpp

