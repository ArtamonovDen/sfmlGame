#include "Vector.h"
//#include "Matrix.h"

#include <iostream>
#include <iomanip>
#include <fstream>
using core::Vector;

Vector::Vector(int row) : row(row){//create empty Vector
	if (row > 0){
		vec = new double[row];
		for (int i = 0; i < row; i++){
			vec[i] = 0;
		}
	}
	else {
		std::cout << "Error in Vector constructor. Row<=0" << std::endl; 
	}

	this->setDim();
};

Vector::Vector() {//create empty Vector ///????
	
};


Vector::Vector(std::string file){
	std::fstream fin;
	fin.open(file);
	fin >> row;
	if (row > 0){
		if (fin.is_open()){
			vec = new double[row];
			for (int i = 0; i < row; i++){
				fin >> vec[i];
			}
		}
	}
	else std::cout << "Error in Vector constructor. Row<=0" << std::endl;

		
	fin.close();

	this->setDim();
}

Vector::Vector(const Vector &B){  //COPY CONSTRUCTOR
	this->row = B.row;
	vec = new double[row];
	for (int i = 0; i < row; i++){
		vec[i] = B.vec[i];
	}

	this->setDim();
}


void Vector::setDim(){
	if (this->is_transposed()){
		//Transposed; 1 x n dim
		this->dim.first = 1;
		this->dim.second = this->row;
	}
	else{
		//Not trasposed; n x 1 dim
		this->dim.first = this->row;
		this->dim.second = 1;
	}
}


Vector Vector::operator = (Vector const & B){ //OPERATOR =
	row = B.row;
	vec = new double[row];
	for (int i = 0; i < row; i++){
		vec[i] = B.vec[i];
	}


	this->setDim();
	return *this;

}


//Vector Vector::operator + (Vector const &B){
//	if (row == B.row){
//		Vector R{ *this };
//		for (int i = 0; i < row; i++){
//			R.vec[i] = vec[i] += B.vec[i];
//		}
//		return R;
//	}
//	
//	
//
//}
//Vector Vector::operator - (Vector const &B){
//	if (row == B.row){
//		Vector R{ *this };
//		for (int i = 0; i < row; i++){
//			R.vec[i] = vec[i] -= B.vec[i];
//		}
//		return R;
//	}
//	return Vector(-1);
//	
//}
//Vector Vector::operator * (double  k){
//	for (int i = 0; i < row; i++){
//		vec[i] *= k;
//	}
//	return *this;
//}

bool Vector::operator < (Vector const &B){
	if (this->size() != B.size())
		return 0;

	bool f = 1;

	int i = 0;
	while ((f) && (i < row)){
		if (this->vec[i] - B.vec[i] >= 0)
			f = 0;
		i++;
	}

	return f;
}

double* Vector::operator [] (int  k){
	if (k < row)
		return &vec[k];
	else
		return nullptr;
}




//core::Matrix   Vector::operator * (const core::Vector & B){
//	if ( this->size() != B.size())
//	{
//		std::cout << "Error in multupluing Vector * Matrix" << std::endl;
//		return{ 0, 0 };
//		
//	}
//
//	//Check Tr of B:
//	core::Matrix X(1, 1);
//	if (this->is_transposed()){
//		//(n x 1) * (1 x n)
//		for (int i = 0; i < this->size(); i++){
//			X.mat[1][1] += this->vec[i] * B.vec[i];
//		}
//	}
//	else{
//		//...
//	}
//	
//	return X;
//}

Vector::~Vector(){

	if (vec != nullptr){
		delete[] vec;
		//std::cout << "--vect--destruct--" << std::endl;

	}
}

void Vector::init_with(double val){
	for (int i = 0; i < size(); i++){
		this->vec[i] = val;
	}
}

void Vector::print(){
	for (int i = 0; i < row; i++){
		std::cout<<std::setw(3) << vec[i] << std::endl;
	}		
	std::cout << std::endl;
}


Vector core::operator +(const core::Vector & A, const core::Vector & B){
	if (A.row == B.row && A.vec != nullptr && B.vec != nullptr){
		Vector X(A.row);
		for (int i = 0; i < A.row; i++){
				X.vec[i] = A.vec[i] + B.vec[i];			
		}
		return X;
	}
	std::cout << "error in vectors addition" << std::endl;
	return{ 0 };
}
Vector core::operator -(const core::Vector & A, const core::Vector & B){
	if (A.row == B.row && A.vec != nullptr && B.vec != nullptr){
		Vector X(A.row);
		for (int i = 0; i < A.row; i++){
			X.vec[i] = A.vec[i] - B.vec[i];
		}
		return X;
	}
	std::cout << "error in vectors subtraction" << std::endl;
	return{ 0 };
}

Vector core::operator *(const core::Vector &A , double k){
	if (A.vec != nullptr){
		Vector X(A.row);
		for (int i = 0; i < A.row; i++){
			X.vec[i] = A.vec[i] * k;
		}
		return X;
	}
	std::cout << "error in multiplying vec on double" << std::endl;
	return{ 0 };
}
Vector core::operator *(double k, const core::Vector &A){
	if (A.vec != nullptr){
		Vector X(A.row);
		for (int i = 0; i < A.row; i++){
			X.vec[i] = A.vec[i] * k;
		}
		return X;
	}
	std::cout << "error in multiplying vec on double" << std::endl;
	return{ 0 };
}

Vector core::operator *(const core::Vector & A, const core::Vector & B) {
	 if (A.row == B.row && A.vec != nullptr && B.vec != nullptr && ( abs(A.transpose - B.transpose) == 1)){ 
		
		if ((A.transpose == 1) && (B.transpose == 0)){
			//1xn * nx1 = 1x1
			Vector X(1);
			for (int i = 0; i < A.row; i++){
				X.vec[0] += A.vec[i] * B.vec[i];
			}
			return X;
		}
		else {
			//nx1 * 1xn = nxn
			core::Matrix X(A.row,B.row);//RETURN MATRIX
			for (int i = 0; i < A.row; i++){
				for (int j = 0; j < B.row; j++){
					X.mat[i][j] = A.vec[i] * B.vec[j];
				}
			}
			//return X; //MATR
		}
		
	}
	std::cout << "error in vector multiplication" << std::endl;
	return{ 0 };
}


Vector Vector::T(){
	//return transposed vector *this
	Vector X(*this);
	X.transpose = 1;
	X.setDim();
	return X;
}