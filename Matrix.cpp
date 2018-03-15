#include "Matrix.h"
#include "Vector.h"

#include <iostream>

#include <fstream>
#include <iomanip>
#include <algorithm>
using core::Matrix;

class core::Vector;
Matrix::Matrix(int row, int col) : row(row), col(col){//create empty matrix


	if ((row > 0) && (col > 0)){
		mat = new double *[row];
		for (int i = 0; i < row; i++){
			mat[i] = new double[col];
			for (int j = 0; j < col; j++){
				mat[i][j] = 0;
			}
		}
	}
	else std::cout << "Error in Matrix constructor" << std::endl;

		

};

Matrix::Matrix(std::string file){
	std::fstream fin;
	fin.open(file);
	fin >> row >> col;
	if ((row > 0) && (col > 0)){
		if (fin.is_open()){
			mat = new double *[row];
			for (int i = 0; i < row; i++){
				mat[i] = new double[col];
				for (int j = 0; j < col; j++){
					fin >> mat[i][j];
				}
			}
		}
	}
	else std::cout << "Error in Matrix constructor" << std::endl;
		
	fin.close();
}

Matrix::Matrix(const Matrix &B){
	this->col = B.col;
	this->row = B.row;
	mat = new double *[row];
	for (int i = 0; i < row; i++){
		mat[i] = new double[col];
		for (int j = 0; j < col; j++){
			mat[i][j] = B.mat[i][j];
		}
	}
}

Matrix::~Matrix(){

	if (mat != nullptr){
		for (int i = 0; i < row; i++){
			delete[] mat[i];
		}
		delete[] mat;
		//std::cout << "--destruct--" << std::endl;	

	}

}

Matrix Matrix::operator = (Matrix const & B){ 
	col = B.col;
	row = B.row;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			mat[i][j] = B.mat[i][j];
		}
	}
	return *this;

}

//core::Vector Matrix::operator[](int k){
//	core::Vector A(row);
//	for (int i = 0; i < row; i++)
//		A.vec[i] = this->mat[i][k];
//	return A;
//}
//
//core::Vector Matrix::operator * (const core::Vector &A){ //T support
//	if (!this->transposed){
//		if (this->col != A.size())
//		{
//			std::cout << "Error in multupluing Vector * Vector" << std::endl;
//			return{0};
//		}
//		core::Vector X(this->row);
//		for (int i = 0; i < this->row; i++){
//			for (int j = 0; j < this->col; j++){
//				X.vec[i] += this->mat[i][j] * A.vec[j];
//			}
//		}
//		return X;
//	}
//	else{
//		if (this->row != A.size())
//		{
//			std::cout << "Error in multupluing Vector * Vector" << std::endl;
//			return{ 0 };
//		}
//		core::Vector X(this->col);
//		for (int i = 0; i < col; i++){
//			for (int j = 0; j < row; j++){
//				X.vec[i] += this->mat[j][i] * A.vec[j];
//			}
//		}
//
//		return X;
//	}
//	
//}
//
//
//core::Matrix Matrix::operator * (const core::Matrix & H){///NOT SUPPORT!
//	if (this->col != H.row )
//	{
//		std::cout << "Error in multupluing Vector * Matrix" << std::endl;
//		return{ 0 };
//	}
//	Matrix X(this->row, H.col);
//	for (int i = 0; i < this->row; i++){
//		for (int k = 0; k < H.col; k++){
//			for (int j = 0; j < this->col; j++){
//				X.mat[i][k] += this->mat[i][j] * H.mat[j][k];
//			}
//		}
//		
//	}
//	return X;
//}

void Matrix::print(){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			std::cout << std::setw(3)<<mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}





//Отдельный алгоритм умножения для гранспонированных и нетрансп матриц?
//следить за трансп




void Matrix::swapRows(int k, int l){
	if (k>=0 && k < row && l>= 0 && l < row ){
		if (k != l){
			for (int i = 0; i < row; i++){
				if ((mat[k][i] != mat[l][i]))
					std::swap(mat[k][i], mat[l][i]);
			}
		}	
	
	}
	else std::cout << "The error in swapRows" << std::endl;
	
}

 core::Matrix core::operator +(const core::Matrix & A, const core::Matrix & B){
	 if (A.col == B.col && A.row == B.row && A.mat != nullptr && B.mat != nullptr){
		  Matrix X(A.row, A.col);
		 for (int i = 0; i < A.row; i++){
			 for (int j = 0; j < A.col; j++){
				 X.mat[i][j] = A.mat[i][j] + B.mat[i][j];
			 }
		 }
		 return X;
	 }
	 std::cout << "error in matrix addition" << std::endl;
	 return{ 0, 0 };
}

 core::Matrix core::operator *(const core::Matrix & A, double k){
	 if (A.mat != nullptr){
		 Matrix X(A.row, A.col);
		 for (int i = 0; i < A.row; i++){
			 for (int j = 0; j < A.col; j++){
				 X.mat[i][j] = A.mat[i][j] *k;
			 }
		 }
		 return X;
	 }
	 std::cout << "error in matrix multipl" << std::endl;
	 return{ 0, 0 };
 }

 //core::Matrix core::operator *(double k,  core::Matrix & A){
	// if (A.mat != nullptr){
	//	 Matrix X(A.row, A.col);
	//	 for (int i = 0; i < A.row; i++){
	//		 for (int j = 0; j < A.col; j++){
	//			 X.mat[i][j] = A.mat[i][j] * k;
	//		 }
	//	 }
	//	 return X;
	// }
	// std::cout << "error in matrix multipl" << std::endl;
	// return{ 0, 0 };
 //}

 core::Matrix core::operator *(const core::Matrix & A, const core::Matrix & B){
	 if (A.col !=B.row || A.mat==nullptr || B.mat == nullptr){
		 std::cout << "error in matrix multipl. Wrong dimension" << std::endl;
		 return{ 0, 0 };
	 }
	 Matrix X(A.row, B.col);
	 for (int i = 0; i < A.row; i++){
		 for (int j = 0; j < B.col; j++){
			 for (int k = 0; k < A.col; k++){
				 X.mat[i][j] += A.mat[i][k] * B.mat[j][k];
			 }
		 }
	 }
	 return X;
 }


core::Matrix Matrix::T(){
	//return new transposed matrix
	Matrix X(this->col, this->row);
	for (int i = 0; i < X.row;i++)
	{
		for (int j = 0; j < X.col;j++){
			X.mat[i][j] = this->mat[j][i];
		}
	}

	return X;
 }