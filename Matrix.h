#ifndef MATRIX_H
#define MATRIX_H


#include"Vector.h"
#include <string>
#include <iostream>

namespace  core{
	

	class Matrix
	{
	public:
		

		Matrix(int col, int row);//create empty zero matrix
		Matrix(std::string file);//create matrix from file
		Matrix(const Matrix &B);//copy constructor

		~Matrix();


		core::Matrix& set_T();
		core::Matrix& unset_T();

		std::pair<int, int> dim; //Dimension(m x n)

		Matrix T();

		void swapRows(int k, int l);
		void print();

		//транспонирование. что лучше, возвращать перестроенную матрицу или просто менять реализацию? 
		//наверное лучше возвращать новый объект/указатель. потому что иначе придётся 
		//делать инверсию, возврат к первоначальной матрице

		Matrix operator = (Matrix const & B);

		friend core::Matrix operator +(const core::Matrix &, const core::Matrix &);
		friend core::Matrix operator *(const core::Matrix &, double k);
		//friend core::Matrix operator *(double k, const core::Matrix &);
		friend core::Matrix operator *(const core::Matrix &, const core::Matrix &);

		//core::Vector operator[](int i); //??

		//core::Vector operator * (const core::Vector &); //Matrix(m x n) * Vector(n x 1) = Vector(m x 1)
		//core::Matrix operator * (const core::Matrix &); //Matrix(m x n) * Matrix(n x r) = Matrix(m x r)
		//friend int operator +(const core::Matrix &, const core::Matrix &);
		
		//core::Matrix operator + (const core::Matrix &A, const core::Matrix & B);

		//core::Matrix operator * (const core::Matrix & A, const core::Vector & B);

		

		//private:
		double** mat{ nullptr };
		int col{ 0 };
		int row{ 0 };
		bool transposed = 0;

	private:
		int x;
	};




//core::Matrix operator + (const core::Matrix &A, const core::Matrix & B){
//	
//	std::cout << "Bin op mat + mat" << std::endl;
//	return{ 0, 0 };
//}



//void  operator + (const core::Matrix & A, const core::Matrix & B){
//	std::cout << A.col + B.col << std::endl;
//	return ;
//}



}
#endif