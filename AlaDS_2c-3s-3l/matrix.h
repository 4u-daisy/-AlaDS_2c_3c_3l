#pragma once
#include <utility>
#include <iostream>
#include <complex>
#include <vector>

struct MyComparator {
	bool operator()(std::complex<double> lhs, std::complex<double> rhs) const {
		return lhs.real() < rhs.real();
	}
	bool operator()(std::complex<int> lhs, std::complex<int> rhs) const {
		return lhs.real() < rhs.real();
	}
	bool operator()(std::complex<float> lhs, std::complex<float> rhs) const {
		return lhs.real() < rhs.real();
	}
};

template <typename T, typename TComparator = std::less < T>>
class matrix {
private:
	std::vector<std::vector<T>> _matr;
	int _columns, _rows;

public:
	matrix() {
		_columns = 0;
		_rows = 0;
	}
	matrix(const int columns, const int rows) {
		_columns = columns;
		_rows = rows;
		std::vector<std::vector<T>> tmp(_columns, std::vector<T>(_rows));
		std::swap(_matr, tmp);
	}

	int get_col() const {
		return _columns;
	}
	int get_row() const {
		return _rows;
	}

	void set_columns(const int columns) {
		_columns = columns;
	}
	void set_rows(const int rows) {
		_rows = rows;
	}

	void swap(const matrix& rhs) {
		matrix<T> tmp = rhs;
		std::swap(_columns, tmp._columns);
		std::swap(_rows, tmp._rows);
		std::swap(_matr, tmp._matr);
	}

	T& operator()(const int columns, const int rows) {
		if (_columns <= columns || _rows <= rows)
			throw::std::out_of_range("error index");
		return _matr[columns][rows];
	}
	T operator()(const int columns, const int rows) const {
		if (_columns <= columns || _rows <= rows)
			throw::std::out_of_range("error index");
		return _matr[columns][rows];
	}

	matrix<T, MyComparator> operator+(const matrix& rhs) {
		if (_rows != rhs._rows || _columns != rhs._columns)
			throw std::logic_error("Matrices with different sizes cannot be added!");

		matrix<T, MyComparator> c(_columns, _rows);

		for (int i = 0; i < c._columns; i++) {
			for (int j = 0; j < c._rows; j++) {
				c._matr[i][j] = _matr[i][j] + rhs._matr[i][j];
			}
		}
		return c;
	}
	//matrix<T> operator-(const matrix& rhs);
	//matrix<T> operator*(const matrix& rhs);
	//matrix<T> operator*(const T rhs);
	//matrix<T> operator/(const T rhs);

	bool operator==(const matrix& rhs) {
		if (_columns != rhs._columns || _rows != rhs._rows)
			throw std::logic_error("Matrices of different sizes!");
		for (int i = 0; i < _columns; i++) {
			for (int j = 0; j < _rows; j++) {
				if (_matr[i][j] != rhs._matr[i][j])
					return false;
			}
		}
		return true;
	}
	bool operator!=(const matrix& rhs) {
		return !this->operator==(rhs);
	}

	bool operator<(const matrix& rhs) {
		if (_rows != rhs._rows || _columns != rhs._columns)
			throw std::logic_error("Matrices of different sizes!");

		for (int i = 0; i < _columns; i++) {
			for (int j = 0; j < _rows; j++) {
				if (TComparator()(_matr[i][j], rhs._matr[i][j]))
					return false;
			}
		}
		return true;
	}
	bool operator>(const matrix& rhs) {
		return !this->operator>(rhs);
	}

	//bool operator>=(const matrix& rhs) {}
	//bool operator>=(const matrix& rhs) {
	//	if (_columns != rhs._columns || _rows != rhs._rows)
	//		throw std::logic_error("Matrices of different sizes!");
	//	//if (std::is_same(std::complex<double>, std::complex<double>)) {
	//	//	/*for (int i = 0; i < _columns; i++) {
	//	//		for (int j = 0; j < _rows; j++) {
	//	//			if (_matr[i][j].real() < rhs._matr[i][j].real() || _matr[i][j].imag() < rhs._matr[i][j].imag())
	//	//				return false;
	//	//		}
	//	//	}*/
	//	//}
	//		for (int i = 0; i < _columns; i++) {
	//			for (int j = 0; j < _rows; j++) {
	//				if (_matr[i][j] < rhs._matr[i][j])
	//					return false;
	//			}
	//	return true;
	//}
	//bool operator<=(const matrix& rhs);
	//bool operator>(const matrix& rhs);
	//bool operator<(const matrix& rhs);
};

template<class T>
double matrix_trace(const matrix<std::complex<T>,MyComparator>& lhs) {
	if (lhs.get_col() != lhs.get_row())
		throw std::logic_error("The matrix is not square!");
	double res = 0;
	for (int i = 0; i < lhs.get_col(); i++) {
		res += lhs(i, i).real();
	}
	return res;
}
template<class T>
double matrix_trace(const matrix<T, MyComparator>& lhs) {
	if ( lhs.get_col() != lhs.get_row())
		throw std::logic_error("The matrix is not square!");
	double res = 0;
	for (int i = 0; i < lhs.get_col(); i++) {
		res += lhs(i, i);
	}
	return res;
}
template<class T>
std::ostream& operator<< (std::ostream& out, const matrix<T, MyComparator>& lhs) {
	for (int i = 0; i < lhs.get_col(); i++) {
		for (int j = 0; j < lhs.get_row(); j++) {
			out << lhs(i, j) << '\t';
		}
		out << '\n';
	}
	return out;
}

template<class T>
std::istream& operator>> (std::istream& in, matrix<T, MyComparator>& lhs) {
	for (int i = 0; i < lhs.get_col(); i++) {
		for (int j = 0; j < lhs.get_row(); j++) {
			std::cout << "Input data [" << i << "][" << j << "] - ";
			in >> lhs(i, j);
		}
	}
	return in;
}
template<class T>
std::istream& operator>>(std::istream& in, matrix<std::complex <T>, MyComparator>& lhs) {
	for (int i = 0; i < lhs.get_col(); i++) {
		for (int j = 0; j < lhs.get_row(); j++) {
			T real = 0, imagine = 0;
			std::cout << "\nData [" << i << ", " << j << "]\nInput real part: ";
			std::cin >> real;
			std::cout << "Input imagine part: ";
			std::cin >> imagine;
			lhs(i, j) = { real, imagine };
		}
	}
	return in;
}