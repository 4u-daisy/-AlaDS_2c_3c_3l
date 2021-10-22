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


matrix<int> random_matrix(const int col, const int row) {
	matrix<int> mtr(col, row);
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			mtr(i, j) = ((rand() + 1) * (rand() + 1)) % 9;
		}
	}
	return mtr;
}


int main() {

	//const int rows = 3, columns = 2;
	//std::vector<std::vector<int>> example(columns, std::vector<int>(rows));
	//for (auto& col : example) {
	//	for (auto& row : col) {
	//		std::cout << "Input data: ";
	//		std::cin >> row;
	//	}
	//}
	//example[0][2] = 2;
	//for (auto& col : example) {
	//	for (auto& row : col) {
	//		std::cout << "Print data: " << row << "   ";
	//	}
	//	std::cout << '\n';
	//}
	
	matrix<int> mtr(3, 3);
	matrix<int> mtr2;
	matrix<int> mtr3(3, 5);

	mtr2.set_columns(3);
	mtr2.set_rows(3);

	mtr = random_matrix(3, 3);
	mtr2 = random_matrix(3, 3);
	

	std::cout << mtr  << "\n\n" << mtr2 << "\n\n" << mtr2 * mtr;

	return 0;
}