#Patrick Ging Makefile

main: main.o
	g++ -o main -std=c++11 main.cpp

tests: tests.o time.o 
	g++ -o tests -std=c++11 tests.o time.o

clean:
	rm a.exe a.out main tests *.o

#.o files
movie.o: movie.h time.h movie.cpp time.cpp
	g++ -c -std=c++11 movie.cpp time.cpp

timeslot.o: timeslot.h movie.h time.h movie.cpp time.cpp timeslot.cpp
	g++ -c -std=c++11 movie.cpp time.cpp timeslot.cpp

time.o: time.h time.cpp
	g++ -c -std=c++11 time.cpp

tests.o: time.cpp doctest.h time.h
	g++ -c -std=c++11 tests.cpp time.cpp

