#include "M_Matrix.h"
#include <memory>

int main() {
	M_Matrix<float> *matrix = new M_Matrix<float>();
	matrix->genGaussianMatrix(5, 5);
	matrix->printMatrix();
	std::cout << "AFTER FLATTEN OPERATION" << std::endl;

	float* fltMTR = matrix->toArray();
	unsigned int size = matrix->mtr.size() * matrix->mtr[0].size();

	try{
		for(int i = 0; i < size; i++){
			std::cout << fltMTR[i] << " ";
			std::cout << "move" << std::endl;
		}
	}
	catch(std::exception& e){
		std::cout << e.what() << std::endl;
	}
	//matrix->genUnitMatrix(400, 400);
	//matrix->printMatrix();
	//std::unique_ptr<M_Matrix<float>> mtr = std::make_unique<M_Matrix<float>>(5, 5);
	//mtr->printMatrix();
	//mtr->genUnitMatrix(5,5);
	//mtr->genGaussianMatrix(5,5);
	//mtr->printMatrix();
	//getchar();
	delete fltMTR;
	delete matrix;
	return 0;
}
