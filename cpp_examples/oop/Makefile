# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

LIBS = -lboost_thread -lboost_system

# the build target executable:
TARGET = oop


all: oop hacker1

oop: oop.cpp
	$(CC) $(CFLAGS) -std=c++11 -o oop oop.cpp $(LIBS)

hacker1: hacker1.cpp
	$(CC) $(CFLAGS) -std=c++11 -o hacker1 hacker1.cpp $(LIBS)



clean:
	$(RM) oop
	$(RM) hacker1
