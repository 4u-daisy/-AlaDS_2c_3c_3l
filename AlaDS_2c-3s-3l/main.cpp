#include "matrix.h"

/*
В данной работе необходимо улучшить свой класс из предыдущей лабораторной работы,
полностью делегировав управление памятью стандартному контейнеру.
1. Конструктор копирования, оператор присваивания и деструктор в классе должны неявно
генерироваться компилятором; при этом операции копирования должны выполнять глубокое
клонирование объекта (т. е. внешнее поведение класса должно остаться таким же, каким и было).
2. Внутри класса не должно остаться ни указателей, ни ручного управления памятью.
3. В качестве поля класса должен появиться стандартный контейнер std::vector или
std::list/std::forward_list (в зависимости от того, использовали вы массив или связный
список в предыдущей лабораторной работе).
4. Элементы, хранящиеся в классе, должны быть константно итерируемыми с помощью rangebased for loop (класс должен иметь методы для предоставления итераторов).

*/

//template<class T>
//bool Example(matrix<T> firstMatrix, matrix<T> secondMatrix, T realPartfirstMatrix = 0, T realPartSecondMatrix = 0) {
//	if (_columns != rhs._columns || _rows != rhs._rows)
//		throw std::logic_error("Matrices of different sizes!");
//	for (int i = 0; i < _columns; i++) {
//		for (int j = 0; j < _rows; j++) {
//			if()
//				return false;
//		}
//	}
//}

template<class T>
bool comparator(matrix<T> firstMatrix, matrix<T> secondMatrix) {
	if (firstMatrix.get_col() != secondMatrix.get_col() || firstMatrix.get_row() != secondMatrix.get_row())
		return false;
	for (int i = 0; i < firstMatrix.get_col(); i++) {
		for (int j = 0; j < firstMatrix.get_row(); j++) {
			if (firstMatrix(i, j).real() != secondMatrix(i, j).real() ||
				firstMatrix(i, j).imag() != secondMatrix(i, j).imag())
				return false;
		}
	}
	return true;
}

//template <class T>
//bool complex_matrix_comparator(const matrix<T>& lhs, const matrix<T>& rhs) {
//	return lhs(0, 0).real() == rhs(0, 0).real() ? lhs(0, 0).imag() < rhs(0, 0).imag() : lhs(0, 0).real() < rhs(0, 0).real();
//}

//template <class T>
//bool complex_comparator(const T lhs, const T rhs) {
//	return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
//}

template <class T>
bool complex_comparator(const T lhs, const T rhs) {
	return lhs.real() == rhs.real() ? lhs.imag() < rhs.imag() : lhs.real() < rhs.real();
}

//template <class T>
//bool comprare(matrix<T> firstMatrix, matrix<T> secondMatrix) {
//	for (int i = 0; i < firstMatrix.get_col(); i++) {
//		for (int j = 0; j < firstMatrix.get_row(); j++) {
//			if (std::is_same(std::complex<double>)) {
//				if (!complex_comparator(firstMatrix(i, j), secondMatrix(i, j)))
//					return false;
//			}
//			else
//				if (firstMatrix(i, j) != secondMatrix(i, j))
//					return false;
//			}
//	}
//}



struct MyComparator1 {
	bool operator()(int a, int b) {
		return b < a;
	}
};

template<typename T, typename TComparator = std::less < T>>
struct ClassWithComparator {
	void Demo() const {
		int a = 5;
		int b = 10;
		std::cout << TComparator()(a, b) << std::endl;
	}
};

int main() {

	//ClassWithComparator<int> o1;
	//ClassWithComparator<int, MyComparator1> o2;
	//o1.Demo();
	//o2.Demo();
	
	//matrix<std::complex<double>, MyComparator> mtr9(2, 2);

	matrix<std::complex<double>, MyComparator> mtr(2, 2);
	matrix<std::complex<double>, MyComparator> mtr2(2, 2);

	matrix<float, MyComparator> mtr3(2, 2);
	matrix<float, MyComparator> mtr4(2, 2);

	std::cin >> mtr >> mtr2;

	std::cin >> mtr3 >> mtr4;

	std::cout << mtr;

	std::cout << mtr3 + mtr4;

	////bool flag = mtr < mtr2;
	//bool flag1 = mtr3 < mtr4;

	//std::cout << matrix_trace(mtr);
	
	//bool flag = comp(mtr, mtr2);


	return 0;
}