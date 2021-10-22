#include "matrix.h"
/*
� ������ ������ ���������� �������� ���� ����� �� ���������� ������������ ������,
��������� ����������� ���������� ������� ������������ ����������.
1. ����������� �����������, �������� ������������ � ���������� � ������ ������ ������
�������������� ������������; ��� ���� �������� ����������� ������ ��������� ��������
������������ ������� (�. �. ������� ��������� ������ ������ �������� ����� ��, ����� � ����).
2. ������ ������ �� ������ �������� �� ����������, �� ������� ���������� �������.
3. � �������� ���� ������ ������ ��������� ����������� ��������� std::vector ���
std::list/std::forward_list (� ����������� �� ����, ������������ �� ������ ��� �������
������ � ���������� ������������ ������).
4. ��������, ���������� � ������, ������ ���� ���������� ������������ � ������� rangebased for loop (����� ������ ����� ������ ��� �������������� ����������).

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