#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"
#include <string>
#include <tuple>
//И мактрица, и вектор в одном заголовке. Матрица через вектора?
namespace  core{
class Vector
{
public:
	Vector(int row);//create empty matrix
	Vector(std::string file);

	 Vector();
	 ~Vector();

	Vector(const Vector &B);

	Vector operator = (Vector const & B);	
	bool operator < (Vector const &B);
	friend Vector operator +(const core::Vector &, const core::Vector &);
	friend Vector operator -(const core::Vector &, const core::Vector &);
	friend Vector operator *(const core::Vector &, double k);
	friend Vector operator *(double k, const core::Vector &);
	friend Vector operator *(const core::Vector &, const core::Vector &);
	double* operator [] (int k);

	Vector T();

	//Vector operator + (Vector const &B);
	//Vector operator - (Vector const &B);
	//Vector operator* (double k);
	
	//Matrix  operator * (const core::Vector & B);


	//Vector operator * (const core::Vector &); //Vector(1 x n) * Vector(n x 1) = double(1 x 1)
	//Vector operator * (const core::Vector &); //Vector(n x 1) * Vector(1 x n) = Matrix(n x n)
	//Matrix operator * (const core::Matrix &); //Vector(n x 1) * Matrix(n x r) = Matrix(m x r)

	//core::Matrix operator * (Vector const & B); 

	
	void print();
	int size() const {	return row;	}
	bool is_transposed() const{ return transpose; }
	void init_with(double);

	std::pair<int, int> dim; //Dimension(m x n)

	

	void setDim();//Set dimension

	double* vec{ nullptr };
	int row{ 0 };
	bool transpose = 0;

	//void* Vector::operator new(size_t v)
	//{
	//	void *ptr = malloc(v);
	//	if (ptr == NULL)
	//		throw std::bad_alloc();
	//	return ptr;
	//}
	////Выделение памяти под несколько объектов
	//void* Vector::operator new[](size_t v)
	//{
	//	void *ptr = malloc(sizeof(Vector)* v);
	//	if (ptr == NULL)
	//		throw std::bad_alloc();
	//	return ptr;
	//}
	//void Vector::operator delete(void* v)
	//{
	//	free(v);
	//}
	//void Vector::operator delete[](void* v)
	//{
	//	free(v);
	//}
	//private:
	
	//транспонирование

};
};

#endif