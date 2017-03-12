CC = g++
FLAGS = -g -Wall -std=c++11
OBJFLAGS = -g -Wall -c -std=c++11

BIN = bin

DataContainer: mkbin DataContainer.o
	$(CC) $(FLAGS) -o $(BIN)/DataContainer main.cpp

DataContainer.o: DataContainer.hpp
	$(CC) $(OBJFLAGS) -o $(BIN)/DataContainer.o DataContainer.hpp

mkbin:
	mkdir -p $(BIN)

.phony:
	all