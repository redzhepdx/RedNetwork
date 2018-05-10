#pragma once
#include "M_Matrix.h"

template <typename T>
bool isInInside(std::vector<std::vector<T>> matrix, int R, int C, int F_R, int F_C){
	int top_r      = (R - (int)(F_R / 2));
	int top_c      = (C - (int)(F_C / 2));
	int bot_r      = (R + (int)(F_R / 2));
	int bot_c      = (C + (int)(F_C / 2));
	bool top_left  = (top_r >= 0) && (top_c >= 0);
	bool bot_right = (bot_r < matrix.size()) && (bot_c < matrix[0].size()); 
	return top_left && bot_right;
}

template <typename T>
std::vector<std::vector<T>> conv2D(const std::vector<std::vector<T>> &matrix, const std::vector<std::vector<T>> &filter){
	
	unsigned int newRow = matrix.size() - filter.size() + 1;
	unsigned int newCol = matrix[0].size() - filter[0].size() + 1;
	std::vector<std::vector<T>> new_matrix(newRow, std::vector<T>(newCol, 0));

	for(int row = 0; row < matrix.size(); row++){
		for(int col = 0; col < matrix[row].size(); col++){
			int sum = 0;
			if (isInInside(matrix, row, col, filter.size(), filter[0].size())){
				for(int filterRow = -((int)filter.size() / 2);
					filterRow <= ((int)filter.size() / 2);
				 	filterRow++){
					for(int filterCol = -((int)filter[0].size() / 2); 
						filterCol <= ((int)filter[0].size() / 2); 
						filterCol++){
						int f_r          = (filterRow + ((int)filter.size() / 2));
						int f_c          = (filterCol + ((int)filter.size() / 2));
						int m_r          = (row + filterRow);
						int m_c          = (col + filterCol);
						sum             += matrix[m_r][m_c] * filter[f_r][f_c];
					}
				}
				new_matrix[row - ((int)filter.size() / 2)][col - ((int)filter[0].size() / 2)] = sum;
			}
		}
	}
	return new_matrix;
}


template <typename T>
std::vector<T> faster_matrix_mul_cpu( std::vector<T> vect,
								      std::vector<T> &values,
								      std::vector<unsigned int> &col_indexes,
								      std::vector<unsigned int> &row_ptr)
{
	std::vector<T> res;
	
	for(unsigned int i = 1; i < row_ptr.size(); i++){
		int sum = 0;
		for(int index = row_ptr[i - 1]; index < row_ptr[i]; index++){
			sum += (values[index] * vect[col_indexes[index]]);
		}
		res.push_back(sum);
	}
	//for(int i = 0; i < res.size(); i++){std::cout << res[i] << std::endl;}
	//std::cout << std::endl;

	return res;
}
