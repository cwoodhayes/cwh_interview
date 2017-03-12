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
	void add(const DataContainer<T_width>& dc);

	//getters
	DataContainer<T_width> getStandardDeviation() const;
	DataContainer<T_width> getMean() const;

	template<size_t, size_t> 
	friend std::ostream& operator<<(std::ostream os, const StatisticsBuffer<N, T_width>& sb) {
		return sb.printSB(os);
	}

	std::ostream& printSB(std::ostream& os) const;
private:
	DataContainer<T_width>* buffer[N];
	//"zeroIndex" tracks the index of the oldest element in the buffer
	int zeroIndex;
	
	//"currIndex" tracks the index of the next open location in the buffer
	int currIndex;

	bool isEmpty;

	void popOldestElement();
	double getMeanOfIndex(int) const;
};

//CLASS METHOD DEFINITIONS////////////////////////////////////////////////

/*default constructor*/
template<size_t N, size_t T_width>
StatisticsBuffer<N,T_width>::StatisticsBuffer() {
	for (int i=0; i<N; i++) {
		buffer[i] = NULL;
	}
	zeroIndex = 0;
	currIndex = 0;
	isEmpty = true;
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
This buffer is implemented as a circular array to avoid unnecessary copying
of the internal DataContainers upon adding, which would be expensive.
*/
template<size_t N, size_t T_width>
void StatisticsBuffer<N, T_width>::add(const DataContainer<T_width>& dc) {
	//if we need to overwrite the oldest element, pop it
	if(!isEmpty && currIndex == zeroIndex) popOldestElement();
	buffer[currIndex] = new DataContainer<T_width>(dc);
	currIndex = (currIndex+1)%N;
	isEmpty = false;
}

//Helper functions/////////////////////////////////////////////////////////

/*
void PopOldestElement()
Deallocates the oldest element in the buffer, and then updates 
zeroIndex to reflect the new location
of the buffer in the circular array.
*/
template<size_t N, size_t T_width>
void StatisticsBuffer<N, T_width>::popOldestElement() {
	delete buffer[zeroIndex];
	buffer[zeroIndex] = NULL;
	zeroIndex = (zeroIndex+1)%N;
}

/*
double getMeanOfIndex(int index)
Returns the mean of all the values at a certain index in the DataContainers
*/
template<size_t N, size_t T_width>
double StatisticsBuffer<N, T_width>::getMeanOfIndex(int index) const {
	double runningTotal=0; int size=0;
	for (int i=0; i<N; i++) {
		if (buffer[i]!=NULL) {
			runningTotal+=(*buffer[i])[index];
			size++;
		}
	}
	return runningTotal/(double)size;
}

//GETTERS////////////////////////////////////////////////////////////////
//stdev
template<size_t N, size_t T_width>
DataContainer<T_width> StatisticsBuffer<N, T_width>::getStandardDeviation() const {
	DataContainer<T_width> out;
	return out;
}

//mean
template<size_t N, size_t T_width>
DataContainer<T_width> StatisticsBuffer<N, T_width>::getMean() const {
	DataContainer<T_width> out;
	for (int i=0; i<T_width; i++) 
		out[i] = getMeanOfIndex(i);
	return out;
}

//printer functions///////////////////////////////////////////////////////
template<size_t N, size_t T_width>
std::ostream& StatisticsBuffer<N, T_width>::printSB(std::ostream& os) const {
	if (isEmpty) std::cout << "--buffer is empty--\n";
	else {
		std::cout << "From oldest to newest:\n" << *buffer[zeroIndex] << "  -- buffer index " << zeroIndex << std::endl;;
		for (int i=(zeroIndex+1)%N; i!=currIndex; i=(i+1)%N) {
			std::cout << *buffer[i] << "  -- buffer index " << i << std::endl;
		}
	}
	return os;
}

#endif