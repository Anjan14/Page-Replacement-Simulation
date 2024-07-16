#********************************************************************
#
# Makefile
#
# This makefile is used to build the simpager executable.
#
#********************************************************************

CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS =

SRC = main.cpp FIFO.cpp LRU.cpp OPT.cpp RAND.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = simpager

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
