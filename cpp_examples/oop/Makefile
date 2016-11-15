# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

LIBS = -lboost_thread -lboost_system

# the build target executable:
TARGET = test


all: test test2 test3 test4

test: test.cpp
	$(CC) $(CFLAGS) -o test test.cpp $(LIBS)

test2: test2.cpp
	$(CC) $(CFLAGS) -std=c++0x -o test2 test2.cpp $(LIBS)

test3: test3.cpp
	$(CC) $(CFLAGS) -std=c++0x -o test3 test3.cpp $(LIBS)

test4: test4.cpp
	$(CC) $(CFLAGS) -std=c++0x -o test4 test4.cpp $(LIBS)


clean:
	$(RM) test
	$(RM) test2
	$(RM) test3
