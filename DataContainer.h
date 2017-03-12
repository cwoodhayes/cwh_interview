#include <array>

template<size_t T_width>
class DataContainer<T_width> : public std::array<double, T_width> {
public:
	DataContainer<T_width> operator+(DataContainer<T_width> lhs, DataContainer<T_width> rhs);
	DataContainer<T_width> operator-(DataContainer<T_width> lhs, DataContainer<T_width> rhs);
	DataContainer<T_width> operator/(DataContainer<T_width> lhs, DataContainer<T_width> rhs);
	DataContainer<T_width>& operator+=(const DataContainer<T_width>& rhs);
	DataContainer<T_width>& operator-=(const DataContainer<T_width>& rhs);

	DataContainer<T_width> Pow(int exp);
	DataContainer<T_width> Sqrt();
};