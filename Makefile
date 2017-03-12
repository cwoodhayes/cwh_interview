#Makefile for honeybee interview assignment
#author: Conor Hayes

CC = g++
FLAGS = -g -Wall -std=c++11
OBJFLAGS = -g -Wall -c -std=c++11

BIN = bin

all: mkbin StatisticsBuffer DataContainer

StatisticsBuffer: StatisticsBuffer.o DataContainer.o
	$(CC) $(FLAGS) -o $(BIN)/StatisticsBuffer SBMain.cpp

StatisticsBuffer.o: StatisticsBuffer.hpp
	$(CC) $(OBJFLAGS) -o $(BIN)/StatisticsBuffer.o StatisticsBuffer.hpp

DataContainer: DataContainer.o
	$(CC) $(FLAGS) -o $(BIN)/DataContainer DCMain.cpp

DataContainer.o: DataContainer.hpp
	$(CC) $(OBJFLAGS) -o $(BIN)/DataContainer.o DataContainer.hpp

mkbin:
	mkdir -p $(BIN)

.phony:
	all mkbin