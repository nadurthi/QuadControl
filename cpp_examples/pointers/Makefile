# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = test

all: test test2

test: test.cpp
	$(CC) $(CFLAGS) -o test test.cpp

test2: test2.cpp
	$(CC) $(CFLAGS) -o test2 test2.cpp

clean:
	$(RM) $(TARGET)
