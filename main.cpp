#include "M_Matrix.h"
#include <memory>

int main() {
	M_Matrix<int> matrix(5, 5);
	matrix.printMatrix();
	std::unique_ptr<M_Matrix<int>> mtr = std::make_unique<M_Matrix<int>>(5, 5);
	mtr->printMatrix();
	getchar();
	return 0;
}