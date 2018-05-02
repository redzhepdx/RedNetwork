#include "M_Matrix.h"

template <typename T>
void M_Matrix<T>::printMatrix() {
	std::cout << "Printing Matrix Wuhu" << std::endl;
}

void M_Matrix<int>::printMatrix() {
	std::cout << "Int Matrix Printing" << std::endl;
}

template <typename T>
M_Matrix<T>::M_Matrix(const M_Matrix<T> &other) {
	this->mtr = other.mtr;
}