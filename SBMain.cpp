#include "DataContainer.hpp"
#include "StatisticsBuffer.hpp"
#include <iostream>

#define DATAROW_LENGTH 4
#define STAT_BUF_LENGTH 5
typedef DataContainer< DATAROW_LENGTH > DataRow;
typedef StatisticsBuffer< STAT_BUF_LENGTH, DATAROW_LENGTH > StatBuf;

using namespace std;

int main() {
	//conduct a visual check of the internal workings of the DataContainer
	//using cout
	StatBuf sb;

	for (int i=0; i<10; i++) {
		DataRow drtemp;
		drtemp.fill(i*i);
		sb.add(drtemp);
		sb.printSB(cout);
		cout << sb.getMean() << endl;
	}
}