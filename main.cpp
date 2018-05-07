#include "M_Matrix.h"
#include <memory>

int main() {
	M_Matrix<float> *matrix = new M_Matrix<float>();
	matrix->genGaussianMatrix(5, 5);
	matrix->printMatrix();
	M_Matrix<float> mtr1;
	//mtr1.genUnitMatrix(3, 3);
	//mtr1.genZeroMatrix(3, 3);
	mtr1.genMatrixWithValue(3, 6, 5.1);
	mtr1.printMatrix();
	std::cout << std::endl;
	//std::cout << "<<<< ZERO MATRIX >>>>" << std::endl;

	M_Matrix<float> mtr2;
	mtr2.genMatrixWithValue(6, 3, 2.6);
	//mtr2.genUnitMatrix(6, 3);
	mtr2.printMatrix();
	std::cout << std::endl;

	std::cout << "Multiplication" << std::endl;
	M_Matrix<float> mtr3 = mtr1 * mtr2;
	mtr3.printMatrix();

	

	float* fltMTR = matrix->toArray();
	unsigned int size = matrix->mtr.size() * matrix->mtr[0].size();
	std::cout << "F_VECTOR FLATTEN OPERATION" << std::endl;
	F_Vector<float> flat = matrix->flatten();
	flat.printVec();

	flat += 3.0;
	flat.printVec();
	std::cout << "AFTER FLATTEN OPERATION" << std::endl;
	try{
		for(uint16_t i = 0; i < size; i++){
			std::cout << fltMTR[i] << " ";
			//std::cout << "move" << std::endl;
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
	getchar();
	return 0;
}
