#pragma once
#include <iostream>
#include "F_Vector.h"

template <typename T>
class M_Matrix {
public:
	M_Matrix(int rows, int cols) { this->rows = rows; this->cols = cols; };
	M_Matrix(const M_Matrix<T> &other);

public:
	M_Matrix<T> genZeroMatrix(int rows, int cols);
	M_Matrix<T> genUnitMatrix(int rows, int cols);
	M_Matrix<T> generateGaussianMatrix(int rows, int cols);
	F_Vector<T> toVector();
	T*			toArray();
	F_Vector<T> flatten();

public:
	M_Matrix<T> operator+(const M_Matrix<T> &other) const;
	M_Matrix<T> operator-(const M_Matrix<T> &other) const;
	M_Matrix<T> operator*(const M_Matrix<T> &other) const;

	M_Matrix<T> hadamardProduct(const M_Matrix<T> &other) const;//Element-wise Multiplication
	F_Vector<T> sparseMatrixMult(const F_Vector<T> &vec) const;//Faster Multiplication On Sparse Matrix

public:
	T getCellValue(int row, int col) { return this->mtr[row][col] };
	void printMatrix();


public:
//GPU OPERATIONS WILL BE ADDED AFTER ALL CPU DONE

private:
	int rows;
	int cols;
	std::vector<std::vector<T>> mtr;
};
