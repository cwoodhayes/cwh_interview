#Makefile for honeybee interview assignment
#author: Conor Hayes

CC = g++
FLAGS = -g -Wall -std=c++11
OBJFLAGS = -g -Wall -c -std=c++11

BIN = bin

all: mkbin StatisticsBuffer DataContainer

StatisticsBuffer: StatisticsBuffer.o DataContainer.o
	$(CC) $(FLAGS) -o $(BIN)/StatisticsBuffer SBMain.cpp

DataContainer: DataContainer.o
	$(CC) $(FLAGS) -o $(BIN)/DataContainer DCMain.cpp

%.o: %.hpp
	$(CC) $(OBJFLAGS) -o $(BIN)/$@ $<

mkbin:
	mkdir -p $(BIN)

clean:
	rm -rf bin/*

.phony:
	all mkbin clean