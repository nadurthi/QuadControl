# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

LIBS = -lboost_thread -lboost_system

# the build target executable:
TARGET = oop


<<<<<<< HEAD
all: oop
=======
all: test test2 test3 test4
>>>>>>> 3562407c66680d296aa0ba9cb45a232557bb880c

oop: oop.cpp
	$(CC) $(CFLAGS) -std=c++11 -o oop oop.cpp $(LIBS)

test4: test4.cpp
	$(CC) $(CFLAGS) -std=c++0x -o test4 test4.cpp $(LIBS)


clean:
	$(RM) oop
