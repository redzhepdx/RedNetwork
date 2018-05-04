#pragma once
#include <iostream>
#include <exception>
#include <string>
#include "F_Vector.h"

template <typename T>
class M_Matrix {

#pragma pack(push, 1)
	struct NonSquaredMatrixException : public std::exception{
			const char* what() const throw(){
				return "Can't Generate Specified Matrix.\nRequirement : Matrix Have To Be Square!\n";
			}
	}NonSquareError;
#pragma pack(pop)

public:
	M_Matrix();
	M_Matrix(unsigned int rows, unsigned int cols);
	M_Matrix(const M_Matrix<T> &other);
	~M_Matrix();

public:
	void genZeroMatrix(unsigned int rows, unsigned int cols);
	void genUnitMatrix(unsigned int rows, unsigned int cols);
	void genGaussianMatrix(unsigned int rows, unsigned int cols);

	F_Vector<T> toVector();
	T*			toArray();
	F_Vector<T> flatten();

public:
	M_Matrix<T> operator+(const M_Matrix<T> &other) const;
	M_Matrix<T> operator-(const M_Matrix<T> &other) const;
	M_Matrix<T> operator*(const M_Matrix<T> &other) const;

	M_Matrix<T> operator+=(const T &value) const;
	M_Matrix<T> operator*=(const T &value) const;
	M_Matrix<T> operator/=(const T &value) const;

	M_Matrix<T> hadamardProduct(const M_Matrix<T> &other) const;//Element-wise Multiplication
	F_Vector<T> sparseMatrixMult(const F_Vector<T> &vec) const;//Faster Multiplication On Sparse Matrix

public:
	T getCellValue(unsigned int row, unsigned int col);
	void printMatrix();


public:
//GPU OPERATIONS WILL BE ADDED AFTER ALL CPU DONE

public:
//SMART POINTER FUNCTIONS

public:
	unsigned int rows;
	unsigned int cols;
	std::vector<std::vector<T>> mtr;
};
