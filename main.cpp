#include "M_Matrix.h"
#include <memory>

int main() {
	M_Matrix<float> *matrix = new M_Matrix<float>();
	matrix->genGaussianMatrix(5, 5);
	matrix->printMatrix();
	

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
