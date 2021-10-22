#pragma once
#include <utility>
#include <iostream>
#include <complex>
#include <vector>

template <class T>
class matrix {
private:
	std::vector<std::vector<T>> _matr;
	int _columns, _rows;

public:
	matrix();
	matrix(const int columns, const int rows);

	int get_col() const;
	int get_row() const;

	void swap(const matrix& rhs);

	void set_columns(const int columns);
	void set_rows(const int rows);

	T& operator()(const int columns, const int rows);
	T operator()(const int columns, const int rows) const;

	matrix<T> operator+(const matrix& rhs);
	matrix<T> operator-(const matrix& rhs);
	matrix<T> operator*(const matrix& rhs);
	matrix<T> operator*(const T rhs);
	matrix<T> operator/(const T rhs);

	bool operator==(const matrix& rhs);
	bool operator!=(const matrix& rhs);
	//bool operator>=(const matrix& rhs);
	//bool operator<=(const matrix& rhs);
	//bool operator>(const matrix& rhs);
	//bool operator<(const matrix& rhs);

	double matrix_trace() const;

};

template<class T>
inline matrix<T>::matrix()
{
	_rows = 0;
	_columns = 0;
}
template<class T>
inline matrix<T>::matrix(const int columns, const int rows)
{
	_rows = rows;
	_columns = columns;
	std::vector<std::vector<T>> tmp(_columns, std::vector<int>(_rows));
	std::swap(_matr, tmp);
}

template<class T>
inline int matrix<T>::get_col() const
{
	return _columns;
}
template<class T>
inline int matrix<T>::get_row() const
{
	return _rows;
}

template<class T>
inline void matrix<T>::swap(const matrix& rhs)
{
	matrix<T> tmp = rhs;
	std::swap(_columns, tmp._columns);
	std::swap(_rows, tmp._rows);
	std::swap(_matr, tmp._matr);
}

template<class T>
inline void matrix<T>::set_columns(const int columns)
{
	_columns = columns;
	std::vector<std::vector<T>> tmp(_columns, std::vector<int>(_rows));
	std::swap(_matr, tmp);
}
template<class T>
inline void matrix<T>::set_rows(const int rows)
{
	_rows = rows;
	std::vector<std::vector<T>> tmp(_columns, std::vector<int>(_rows));
	std::swap(_matr, tmp);
}

template<class T>
inline T& matrix<T>::operator()(const int columns, const int rows)
{
	if (_columns < columns || _rows <= rows)
		throw::std::out_of_range("error index");
	return _matr[columns][rows];
}
template<class T>
inline T matrix<T>::operator()(const int columns, const int rows) const
{
	if (_columns < columns || _rows <= rows)
		throw::std::out_of_range("error index");
	return _matr[columns][rows];
}

template<class T>
inline matrix<T> matrix<T>::operator+(const matrix& rhs)
{
	if (_columns != rhs._columns || _rows != rhs._rows)
		throw std::logic_error("error");
	matrix<T> res(rhs._columns, rhs._rows);
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < _rows; j++) {
			res._matr[i][j] = _matr[i][j] + rhs._matr[i][j];
		}
	}
	return res;
}
template<class T>
inline matrix<T> matrix<T>::operator-(const matrix& rhs)
{
	if (_columns != rhs._columns || _rows != rhs._rows)
		throw std::logic_error("error");
	matrix<T> res(_columns, _rows);
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < _rows; j++) {
			res._matr[i][j] = _matr[i][j] - rhs._matr[i][j];
		}
	}
	return res;
}
template<class T>
inline matrix<T> matrix<T>::operator*(const matrix& rhs)
{
	if (_rows != rhs._columns)
		throw std::logic_error("Matrices of different sizes!");
	matrix res(_columns, rhs._rows);
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < rhs._rows; j++) {
			res._matr[i][j] = 0;
			for (int k = 0; k < _rows; k++) {
				res._matr[i][j] += _matr[i][k] * rhs._matr[k][j];
			}
		}
	}
	return res;
}
template<class T>
inline matrix<T> matrix<T>::operator*(const T rhs)
{
	matrix<T> res(_columns, _rows);
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < _rows; j++) {
			res._matr[i][j] = _matr[i][j] * rhs;
		}
	}
	return res;
}
template<class T>
inline matrix<T> matrix<T>::operator/(const T rhs)
{
	matrix<T> res(_columns, _rows);
	for (int i = 0; i < _columns; i++) {
		for (int j = 0; j < _rows; j++) {
			res._matr[i][j] = _matr[i][j] / rhs;
		}
	}
	return res;
}



template<class T>
inline double matrix<T>::matrix_trace() const
{
	if (_columns != _rows)
		throw std::logic_error("The matrix is not square!");
	double res = 0;
	for (int i = 0; i < _columns; i++) {
		res += _data[i][i];
	}
	return res;
}



template<class T>
std::ostream& operator<< (std::ostream& out, const matrix<T>& lhs) {
	for (int i = 0; i < lhs.get_col(); i++) {
		for (int j = 0; j < lhs.get_row(); j++) {
			out << lhs(i, j) << '\t';
		}
		out << '\n';
	}
	return out;
}
template<class T>
std::istream& operator>> (std::istream& in, matrix<T>& lhs) {
	for (int i = 0; i < lhs.get_col(); i++) {
		for (int j = 0; j < lhs.get_row(); j++) {
			std::cout << "Input data [" << i << "][" << j << "] - ";
			in >> lhs(i, j);
		}
	}
	return in;
}
