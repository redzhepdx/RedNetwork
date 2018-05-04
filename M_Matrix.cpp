#include "M_Matrix.h"
#include <cmath>

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
    this->mtr = other.mtr;
}

template M_Matrix<int>::M_Matrix(const M_Matrix<int> &other);
template M_Matrix<float>::M_Matrix(const M_Matrix<float> &other);

template <typename T>
M_Matrix<T>::~M_Matrix(){
	delete this;
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

template <typename T>
F_Vector<T> M_Matrix<T>::toVector(){
	
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

/*OPERATORS*/

