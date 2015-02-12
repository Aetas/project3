#sheblamo
CC=g++
CFLAGr=-Wall -Werror -std=c++0x
#
#WKDIR=($(HOME)/programs/csci-2270/project3/)

all: program

program: Assignment3.cpp
	$(CC) $(CFLAGS) Assignment3.cpp -o Assignment3.o

clean:
	rm *o Assignment3

