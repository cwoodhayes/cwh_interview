#include "DataContainer.hpp"
#include "StatisticsBuffer.hpp"
#include <iostream>

#define DATAROW_LENGTH 6
#define STAT_BUF_LENGTH 10
typedef DataContainer< DATAROW_LENGTH > DataRow;
typedef StatisticsBuffer< STAT_BUF_LENGTH, DATAROW_LENGTH > StatBuf;

using namespace std;

int main() {
	//conduct a visual check of the internal workings of the DataContainer
	//using cout
	StatBuf sb;

	for (int i=0; i<20; i++) {
		DataRow drtemp;
		for (int j=0; j<DATAROW_LENGTH; j++) 
			drtemp[j] = i*i + j;
		sb.add(drtemp);
		sb.printSB(cout);
		cout << "Mean:  " << sb.getMean() << endl;
		cout << "Stdev: " << sb.getStandardDeviation() << endl;
	}
}