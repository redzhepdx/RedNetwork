#include "M_Matrix.h"

//OOP Reqs

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
