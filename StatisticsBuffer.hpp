#ifndef STATISTICS_BUFFER
#define STATISTICS_BUFFER

#include "DataContainer.hpp"

/*
Class definition for StatisticsBuffer.
template args:
	N 		-- the length of the buffer
	T_width -- the width of each element in the buffer
*/
template<size_t N, size_t T_width>
class StatisticsBuffer {
public:
	StatisticsBuffer();
	~StatisticsBuffer();
	void add(DataContainer<T_width>& dc);

	//getters
	double getStandardDeviationI(int index);
	double getMeanI(int index);

	double getStandardDeviationAll();
	double getMeanAll();

private:
	DataContainer<T_width>* buffer[N];
	//"zeroIndex" tracks the index of the oldest element in the buffer
	int zeroIndex;
	
	//"currIndex" tracks the index of the next open location in the buffer
	int currIndex;
	
	//"size" tracks the number of elements currently in the buffer
	int size;		

	void popOldestElement();
};

//CLASS METHOD DEFINITIONS

/*default constructor*/
template<size_t N, size_t T_width>
StatisticsBuffer<N,T_width>::StatisticsBuffer() {
	for (int i=0; i<N; i++) {
		buffer[i] = NULL;
	}
	zeroIndex = 0;
	size = 0;
}

/*destructor*/
template<size_t N, size_t T_width>
StatisticsBuffer<N, T_width>::~StatisticsBuffer() {
	for (int i=0; i<N; i++) {
		delete buffer[i];
	}
}

/*
void Add()
Add a new element to the next open spot in the buffer.
*/
template<size_t N, size_t T_width>
void StatisticsBuffer<N, T_width>::add(DataContainer<T_width>& dc) {
	this->popOldestElement();
	buffer[4];
}

/*
void PopOldestElement()
Deallocates the oldest element in the buffer, and then updates 
zeroIndex and currIndex (and size, if necessary) to reflect the new location
of the buffer in the circular array.
*/
template<size_t N, size_t T_width>
void StatisticsBuffer<N, T_width>::popOldestElement() {
	//pop it
}

//GETTERS//
template<size_t N, size_t T_width>
double StatisticsBuffer<N, T_width>::getStandardDeviationI(int index) {
	return 5.0;
}

template<size_t N, size_t T_width>
double StatisticsBuffer<N, T_width>::getMeanI(int index) {
	return 5.0;
}

template<size_t N, size_t T_width>
double StatisticsBuffer<N, T_width>::getStandardDeviationAll() {
	return 5.0;
}

template<size_t N, size_t T_width>
double StatisticsBuffer<N, T_width>::getMeanAll() {
	return 5.0;
}

#endif