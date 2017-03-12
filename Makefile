CC = g++
FLAGS = -g -Wall

BIN = bin

DataContainer: DataContainer.o
	$(CC) $(FLAGS) -o DataContainer $^

DataContainer.o: DataContainer.hpp
	$(CC) $(FLAGS) -c $^