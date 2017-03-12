#include <array>

using namespace std;

template<size_t T_width>
class DataContainer : public std::array<double, T_width> {
public:
	DataContainer operator+(DataContainer<T_width> rhs) {
		DataContainer<T_width> out;
		for (int i=0; i<T_width; i++) {
			out[i] = (*this)[i] + rhs[i];
		}
	}

	DataContainer operator-(DataContainer<T_width> rhs) {

	}

	DataContainer operator/(int rhs) {

	}

	DataContainer& operator+=(const DataContainer<T_width>& rhs) {

	}

	DataContainer& operator-=(const DataContainer<T_width>& rhs) {

	}

	DataContainer Pow(int exp) {

	}

	DataContainer Sqrt() {

	}
};