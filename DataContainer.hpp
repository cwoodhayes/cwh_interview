#ifndef DATA_CONTAINER
#define DATA_CONTAINER

#include <array>
#include <cmath>
#include <iostream>

template<size_t T_width>
class DataContainer : public std::array<double, T_width> {
public:
	DataContainer operator+(DataContainer<T_width> rhs) const {
		DataContainer<T_width> out;
		for (int i=0; i<T_width; i++) {
			out[i] = (*this)[i] + rhs[i];
		}
		return out;
	}

	DataContainer operator-(DataContainer<T_width> rhs) const {
		DataContainer<T_width> out;
		for (int i=0; i<T_width; i++) {
			out[i] = (*this)[i] - rhs[i];
		}
		return out;
	}

	DataContainer operator/(int rhs) const {
		DataContainer<T_width> out;
		for (int i=0; i<T_width; i++) {
			out[i] = (*this)[i]/rhs;
		}
		return out;
	}

	DataContainer& operator+=(const DataContainer<T_width>& rhs) {
		for (int i=0; i<T_width; i++) {
			(*this)[i]+=rhs[i];
		}
		return *this;
	}

	DataContainer& operator-=(const DataContainer<T_width>& rhs) {
		for (int i=0; i<T_width; i++) {
			(*this)[i]-=rhs[i];
		}
		return *this;
	}

	DataContainer Pow(int exp) const {
		DataContainer<T_width> out;
		for (int i=0; i<T_width; i++) {
			out[i] = pow((*this)[i], exp);
		}
		return out;
	}

	DataContainer Sqrt() const {
		DataContainer<T_width> out;
		for (int i=0; i<T_width; i++) {
			out[i] = sqrt((*this)[i]);
		}
		return out;
	}

	friend std::ostream& operator<<(std::ostream& os, const DataContainer<T_width>& dc) {
		os << "[";
		for (int i=0; i<T_width-1; i++) {
			os << dc[i] << ", ";
		}
		os << dc[T_width-1] << "]";
		return os;
	}
};

#endif

