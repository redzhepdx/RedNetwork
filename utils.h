#pragma once
#include "M_Matrix.h"

template <typename T>
bool isInInside(M_Matrix<T> matrix, unsigned int R, unsigned int C){
	return (matrix.rows > R) && (matrix.cols > C) && (R >= 0) && (C >= 0);
}

template <typename T>
M_Matrix<T> conv2D(M_Matrix<T> matrix, M_Matrix<T> filter){
	M_Matrix<T> new_matrix;

	unsigned int newRow = matrix.rows - filter.rows + 1;
	unsigned int newCol = matrix.cols - filter.cols + 1;

	new_matrix.genZeroMatrix(newRow, newCol);

	for(unsigned int row = 0; row < matrix.rows; row++){
		for(unsigned int col = 0; col < matrix.cols; col++){
			int sum = 0;
			if (isInInside(matrix, matrix.rows, matrix.cols)){
				for(int filterRow = -((int)filter.rows / 2); filterRow <= (filter.rows / 2); filterRow++){
					for(int filterCol = -((int)filter.cols / 2); filterCol <= (filter.cols / 2); filterCol++){
						unsigned int f_r = (filterRow + filter.rows / 2) * filter.cols;
						unsigned int f_c = (filterCol + filter.cols / 2);
						unsigned int m_r = (row + filterRow)* matrix.cols;
						unsigned int m_c = (col + filterCol);
						sum             += matrix.mtr[m_r][m_c] * filter.mtr[f_r][f_c];
					}
				}
				new_matrix.mtr[row - (filter.rows / 2)][col - (filter.cols / 2)] = sum;
			}
		}
	}
	return new_matrix;
}


template <typename T>
F_Vector<T> faster_matrix_mul_cpu( F_Vector<T> vect,
								   std::vector<T> &values,
								   std::vector<unsigned int> &col_indexes,
								   std::vector<unsigned int> &row_ptr)
{
	F_Vector<T> res;

	for(unsigned int i = 1; i < row_ptr.size(); i++){
		int sum = 0;
		for(int index = row_ptr[i - 1]; index < row_ptr[i]; index++){
			sum += (values[index] * vect.vec[col_indexes[index]]);
		}
		res.vec.push_back(sum);
	}

	return res;
}
