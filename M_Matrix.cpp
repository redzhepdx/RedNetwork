#include "M_Matrix.h"
#include "Setup.h"
#include "utils.h"
#include <memory>
#include <algorithm>
#include <cmath>

#if CPU
//OOP Reqs
template <typename T>
M_Matrix<T>::M_Matrix(){

}

template M_Matrix<uint8_t>::M_Matrix();
template M_Matrix<float>::M_Matrix();
template M_Matrix<int>::M_Matrix();

template <typename T>
M_Matrix<T>::M_Matrix(unsigned int rows, unsigned int cols){
	this->rows = rows;
	this->cols = cols;
	this->mtr.resize(this->rows, std::vector<T>(this->cols));
}

template M_Matrix<uint8_t>::M_Matrix(unsigned int rows, unsigned int cols);
template M_Matrix<int>::M_Matrix(unsigned int rows, unsigned int cols);
template M_Matrix<float>::M_Matrix(unsigned int rows, unsigned int cols);

template <typename T>
M_Matrix<T>::M_Matrix(const M_Matrix<T> &other) {
	this->mtr  = other.mtr;
	this->rows = other.cols;
	this->cols = other.cols;
}

template M_Matrix<int>::M_Matrix(const M_Matrix<int> &other);
template M_Matrix<float>::M_Matrix(const M_Matrix<float> &other);
template M_Matrix<uint8_t>::M_Matrix(const M_Matrix<uint8_t> &other);

template <typename T>
M_Matrix<T>::~M_Matrix(){
	this->mtr.clear();
}

template M_Matrix<int>::~M_Matrix();
template M_Matrix<float>::~M_Matrix();
template M_Matrix<uint8_t>::~M_Matrix();


//GETTER SETTER AND UTILS

template <typename T>
void M_Matrix<T>::printMatrix() {
	for(unsigned int row = 0; row < this->rows; row++){
		for(unsigned int col = 0; col < this->cols; col++){
			std::cout << this->mtr[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

template void M_Matrix<float>::printMatrix();
template void M_Matrix<int>::printMatrix();
template void M_Matrix<uint8_t>::printMatrix();

template<>
void M_Matrix<char>::printMatrix() {
	std::cout << "Char Matrix Configuration Will be Different " << std::endl;
}

template <typename T>
T M_Matrix<T>::getCellValue(unsigned int row, unsigned int col){
	return this->mtr[row][col];
}

template int     M_Matrix<int>::getCellValue(unsigned int row, unsigned int col);
template float   M_Matrix<float>::getCellValue(unsigned int row, unsigned int col);
template uint8_t M_Matrix<uint8_t>::getCellValue(unsigned int row, unsigned int col);

/*Matrix Generation Codes*/
template <typename T>
void M_Matrix<T>::genZeroMatrix(unsigned int rows, unsigned int cols){
	int zero  = 0;
	this->rows = rows;
	this->cols = cols;

	std::vector<std::vector<T>> zeros_matrix(rows, std::vector<T>(cols, (T)zero));
	this->mtr = zeros_matrix;
}

template void M_Matrix<int>::genZeroMatrix(unsigned int rows, unsigned int cols);
template void M_Matrix<float>::genZeroMatrix(unsigned int rows, unsigned int cols);
template void M_Matrix<uint8_t>::genZeroMatrix(unsigned int rows, unsigned int cols);

template <typename T>
void M_Matrix<T>::genUnitMatrix(unsigned int rows, unsigned int cols){
	int one = 1;
	try{
		if(rows != cols){
			throw NonSquareError;
		}
		this->rows = rows;
		this->cols = cols;
		this->mtr.resize(this->rows, std::vector<T>(this->cols));

		for(unsigned int diagonal = 0; diagonal < this->rows; diagonal++){
			this->mtr[diagonal][diagonal] = (T)one;
		}
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

template void M_Matrix<int>::genUnitMatrix(unsigned int rows, unsigned int cols);
template void M_Matrix<float>::genUnitMatrix(unsigned int rows, unsigned int cols);
template void M_Matrix<uint8_t>::genUnitMatrix(unsigned int rows, unsigned int cols);

#ifndef T_PI
#define T_PI 3.0
#endif

template <typename T>
void M_Matrix<T>::genGaussianMatrix(unsigned int rows, unsigned int cols){
	const float  sigma = 10.0;
	float  sum   = 0;
	float  r, s  = 2.0 * sigma * sigma;
	try{
		if(rows != cols){
			throw NonSquareError;
		}
		this->rows = rows;
		this->cols = cols;
		this->mtr.resize(this->rows, std::vector<T>(this->cols));
		
		for(int row = -((int)rows / 2); row <= (int)rows/2; row++){
			for(int col = -((int)cols / 2); col <= (int)cols/2; col++){
				r                               = std::sqrt(row * row + col * col);
				int row_index                   = row + (int)rows / 2;
				int col_index                   = col + (int)cols / 2;
				this->mtr[row_index][col_index] = (std::exp(-(r * r) / s)) / (T_PI * s);
				sum                            += this->mtr[row_index][col_index];
			}
		}
		for(unsigned int row = 0; row < rows; row++){
			for(unsigned int col = 0; col < rows; col++){
				this->mtr[row][col] /= sum;
			}
		}
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
}
template void M_Matrix<float>::genGaussianMatrix(unsigned int rows, unsigned int cols);
template void M_Matrix<double>::genGaussianMatrix(unsigned int rows, unsigned int cols);


template <typename T>
F_Vector<T> M_Matrix<T>::toVector(){
	F_Vector<T> _vec;
	_vec.size = this->rows * this->cols;
	for(unsigned int row = 0; row < this->rows; row++){
		for(unsigned int col = 0; col < this->cols; col++){
			_vec.vec.push_back(this->mtr[row][col]);
		}
	}

	return _vec;
}

template F_Vector<int> M_Matrix<int>::toVector();
template F_Vector<float> M_Matrix<float>::toVector();
template F_Vector<uint8_t> M_Matrix<uint8_t>::toVector();

template <typename T>
T* M_Matrix<T>::toArray(){
	T* flat_arr = new T[this->rows * this->cols];
	for(unsigned int row = 0; row < this->rows; row++){
		for(unsigned int col = 0; col < this->cols; col++){
			flat_arr[row * this->cols + col] = this->mtr[row][col];
		}
	}
	return flat_arr;
}

template int* M_Matrix<int>::toArray();
template float* M_Matrix<float>::toArray();
template uint8_t* M_Matrix<uint8_t>::toArray();

template <typename T>
F_Vector<T> M_Matrix<T>::flatten(){
	F_Vector<T> vec(this->rows * this->cols, false);

	for (unsigned int row = 0; row < this->rows; row++) {
		for (unsigned int col = 0; col < this->cols; col++) {
			vec.vec.push_back(this->mtr[row][col]);
		}
	}

	return vec;
}

template F_Vector<int> M_Matrix<int>::flatten();
template F_Vector<float> M_Matrix<float>::flatten();
template F_Vector<uint8_t> M_Matrix<uint8_t>::flatten();

template <typename T>
void M_Matrix<T>::genMatrixWithValue(unsigned int rows, unsigned int cols, T value){
	this->rows = rows;
	this->cols = cols;

	std::vector<std::vector<T>> value_mtr(this->rows, std::vector<T>(this->cols, value));
	this->mtr  = value_mtr;
}

template void M_Matrix<int>::genMatrixWithValue(unsigned int rows, unsigned int cols, int value);
template void M_Matrix<float>::genMatrixWithValue(unsigned int rows, unsigned int cols, float value);
template void M_Matrix<uint8_t>::genMatrixWithValue(unsigned int rows, unsigned int cols, uint8_t value);

template <typename T>
void M_Matrix<T>::transpose(){
	M_Matrix<T> holder;
	holder.genZeroMatrix(this->cols, this->rows);
	for(unsigned int row = 0; row < this->rows; row++){
		for(unsigned int col = 0; col < this->cols; col++){
			holder.mtr[col][row] = this->mtr[row][col];
		}
	}
	this->mtr = holder.mtr;
}
template void M_Matrix<int>::transpose();
template void M_Matrix<float>::transpose();
template void M_Matrix<uint8_t>::transpose();
template void M_Matrix<size_t>::transpose();

/*OPERATORS*/
template <typename T>
M_Matrix<T> & M_Matrix<T>::operator=(const M_Matrix<T> &other){
	this->rows = other.rows;
	this->cols = other.cols;
	this->mtr  = other.mtr;
	return *this;
}

template M_Matrix<int> & M_Matrix<int>::operator=(const M_Matrix<int> &other);
template M_Matrix<float> & M_Matrix<float>::operator=(const M_Matrix<float> &other);
template M_Matrix<uint8_t> & M_Matrix<uint8_t>::operator=(const M_Matrix<uint8_t> &other);
template M_Matrix<size_t> & M_Matrix<size_t>::operator=(const M_Matrix<size_t> &other);

template <typename T>
M_Matrix<T> M_Matrix<T>::operator*(const M_Matrix<T> &other) const {
	M_Matrix<T> matrix;
	try {
		if (this->cols != other.rows) {
			throw InvalidMatrixSize;
		}
		matrix.genZeroMatrix(this->rows, other.cols);
		
		for (unsigned int row = 0; row < this->rows; row++) {
			for (unsigned int col = 0; col < other.cols; col++) {
				for (unsigned int k = 0; k < other.rows; k++) {
					matrix.mtr[row][col] += (this->mtr[row][k] * other.mtr[k][col]);
				}
			}
		}
		//matrix.printMatrix();
		return matrix;
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return matrix;
}
template M_Matrix<int> M_Matrix<int>::operator*(const M_Matrix<int> &other) const;
template M_Matrix<float> M_Matrix<float>::operator*(const M_Matrix<float> &other) const;
template M_Matrix<uint8_t> M_Matrix<uint8_t>::operator*(const M_Matrix<uint8_t> &other) const;

template <typename T>
M_Matrix<T> M_Matrix<T>::operator+(const M_Matrix<T> &other) const {
	M_Matrix<T> _mtr;
	_mtr.genZeroMatrix(this->rows, this->cols);
	for (unsigned int row = 0; row < this->rows; row++) {
		for (unsigned int col = 0; col < this->cols; col++) {
			_mtr.mtr[row][col] = this->mtr[row][col] + other.mtr[row][col];
		}
	}
	return _mtr;
}

template M_Matrix<int> M_Matrix<int>::operator+(const M_Matrix<int> &other) const;
template M_Matrix<float> M_Matrix<float>::operator+(const M_Matrix<float> &other) const;
template M_Matrix<uint8_t> M_Matrix<uint8_t>::operator+(const M_Matrix<uint8_t> &other) const;

template <typename T>
M_Matrix<T> M_Matrix<T>::operator-(const M_Matrix<T> &other) const {
	M_Matrix<T> _mtr;
	_mtr.genZeroMatrix(this->rows, this->cols);
	for (unsigned int row = 0; row < this->rows; row++) {
		for (unsigned int col = 0; col < this->cols; col++) {
			_mtr.mtr[row][col] = this->mtr[row][col] - other.mtr[row][col];
		}
	}
	return _mtr;
}

template M_Matrix<int> M_Matrix<int>::operator-(const M_Matrix<int> &other) const;
template M_Matrix<float> M_Matrix<float>::operator-(const M_Matrix<float> &other) const;
template M_Matrix<uint8_t> M_Matrix<uint8_t>::operator-(const M_Matrix<uint8_t> &other) const;

template <typename T>
void M_Matrix<T>::operator+=(const T & value){
	for (unsigned int row = 0; row < this->rows; row++) {
		for (unsigned int col = 0; col < this->cols; col++) {
			this->mtr[row][col] += value;
		}
	}
}

template void M_Matrix<int>::operator+=(const int & other);
template void M_Matrix<float>::operator+=(const float & other);
template void M_Matrix<uint8_t>::operator+=(const uint8_t & other);

template <typename T>
void M_Matrix<T>::operator-=(const T & value) {
	for (unsigned int row = 0; row < this->rows; row++) {
		for (unsigned int col = 0; col < this->cols; col++) {
			this->mtr[row][col] -= value;
		}
	}
}

template void M_Matrix<int>::operator-=(const int & other);
template void M_Matrix<float>::operator-=(const float & other);
template void M_Matrix<uint8_t>::operator-=(const uint8_t & other);

template <typename T>
void M_Matrix<T>::operator*=(const T & value) {
	for (unsigned int row = 0; row < this->rows; row++) {
		for (unsigned int col = 0; col < this->cols; col++) {
			this->mtr[row][col] *= value;
		}
	}
}

template void M_Matrix<int>::operator*=(const int & other);
template void M_Matrix<float>::operator*=(const float & other);
template void M_Matrix<uint8_t>::operator*=(const uint8_t & other);

template <typename T>
void M_Matrix<T>::operator/=(const T & value) {
	for (unsigned int row = 0; row < this->rows; row++) {
		for (unsigned int col = 0; col < this->cols; col++) {
			this->mtr[row][col] /= value;
		}
	}
}

template void M_Matrix<int>::operator/=(const int & other);
template void M_Matrix<float>::operator/=(const float & other);
template void M_Matrix<uint8_t>::operator/=(const uint8_t & other);

template <typename T>
M_Matrix<T> M_Matrix<T>::hadamardProduct(const M_Matrix<T> &other) const{
	M_Matrix<T> matrix;
	try{
		if(this->rows == other.rows && this->cols == other.cols){
			matrix.genZeroMatrix(this->rows, this->cols);
			//Direct Multiplication
			for(unsigned int row = 0; row < this->rows; row++){
				for(unsigned int col = 0; col < this->cols; col++){
					matrix.mtr[row][col] = this->mtr[row][col] * other.mtr[row][col];
				}
			}
			return matrix;
		}
		else if(this->rows > other.rows && this->cols > other.cols){
			//Convolution
			unsigned int newRow = this->rows - other.cols + 1;
			unsigned int newCol = this->cols - other.cols + 1;
			matrix.rows = newRow;
			matrix.cols = newCol;
			matrix.mtr = conv2D<T>(this->mtr, other.mtr);
			return matrix;
		}
		else{
			throw InvalidMatrixSize;
		}
	}
	catch (std::exception &ex){
		std::cout << ex.what() << std::endl;
	}
	return matrix;
}

template M_Matrix<int> M_Matrix<int>::hadamardProduct(const M_Matrix<int> &other) const;
template M_Matrix<float> M_Matrix<float>::hadamardProduct(const M_Matrix<float> &other) const;
template M_Matrix<uint8_t> M_Matrix<uint8_t>::hadamardProduct(const M_Matrix<uint8_t> &other) const;

template <typename T>
F_Vector<T> M_Matrix<T>::sparseMatrixMult(const F_Vector<T> &vec) const{
	F_Vector<T>               res_vec;
	std::vector<T>            values;
	std::vector<unsigned int> col_indexes;
	std::vector<unsigned int> row_ptr;

	for(int i = 0; i < this->rows; i++){
		bool row_ptr_found = false;
		for(int j = 0; j < this->cols; j++){
			if(this->mtr[i][j] != 0){
				values.push_back(this->mtr[i][j]);
				col_indexes.push_back(j);
				if(!row_ptr_found){
					row_ptr.push_back(values.size() - 1);
					row_ptr_found = true;
				}

			}
		}
	}
	row_ptr.push_back(values.size());
	
	res_vec.vec  = faster_matrix_mul_cpu(vec.vec, values, col_indexes, row_ptr);
	res_vec.size = this->rows;

	return res_vec;
}

template F_Vector<int> M_Matrix<int>::sparseMatrixMult(const F_Vector<int> &vec) const;
template F_Vector<float> M_Matrix<float>::sparseMatrixMult(const F_Vector<float> &vec) const;
template F_Vector<uint8_t> M_Matrix<uint8_t>::sparseMatrixMult(const F_Vector<uint8_t> &vec) const;

#endif
