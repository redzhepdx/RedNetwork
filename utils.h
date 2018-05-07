#pragma once
#include<"M_Matrix.h"

template <typename T, unsigned int R, unsigned int C>
bool isInInside(M_Matrix<T> matrix){
	return (matrix.rows > R) && (matrix.cols > C) && (R >= 0) && (C >= 0);
}

//Not finished Yet
template <typename T>
M_Matrix<T> conv2D(M_Matrix<T> matrix, M_Matrix<T> filter){
	M_Matrix<T> new_matrix;

	unsigned int newRow = this.rows - filter.rows + 1;
	unsigned int newCol = this.cols - filter.cols + 1;

	new_matrix.genZeroMatrix(newRow, newCol);

	for(unsigned int row = 0; row < matrix.rows; row++){
		for(unsigned int col = 0; col < matrix.cols; col++){
			int sum = 0;
			for(int filterRow = -(filter.rows / 2); filterRow <= (filter.rows / 2); filterRow++){
				for(int filterCol = -(filter.cols / 2); filterCol <= (filter.cols / 2); filterCol++){
					unsigned int f_r = (filterRow + filter.rows / 2) * filter.cols;
					unsigned int f_c = (filterCol + filter.cols / 2);
					unsigned int m_r = (row + filterRow)* matrix.cols;
					unsigned int m_c = (col + filterCol);
					sum             += mtr.mtr[m_r][m_c] * filter.mtr[f_r][f_c];
            	}				
			}
		}
	}
}
