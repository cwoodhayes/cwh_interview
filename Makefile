CC = g++
FLAGS = -g -Wall
OBJFLAGS = -g -Wall -c

BIN = bin

DataContainer: mkbin DataContainer.o
	$(CC) $(FLAGS) -o $(BIN)/DataContainer $^

DataContainer.o: DataContainer.cpp DataContainer.hpp
	$(CC) $(OBJFLAGS) -o $(BIN)/DataContainer.o DataContainer.cpp

mkbin:
	mkdir -p $(BIN)

.phony:
	all