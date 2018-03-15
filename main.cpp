#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <algorithm>

using core::Matrix;
using core::Vector;


Vector gauss(Matrix A, Vector B){
	//A - matrix, system of equations
	//B - vector, results

	bool ex_flag = 0;
	if (!( (A.row == A.col) &&(A.col == B.size()) )){
		std::cout << "error. unsuitable dimensions" << std::endl;
		ex_flag = 1;
	}
	

	//CHECK SIZE

	//STRAIGHT RUN
	
	for (int k = 0; (k < A.row - 1)&&(!ex_flag); k++){
		if (A.mat[k][k] == 0){
			int l = k;

			do{
				l++;
				if ((A.mat[l][k] == 0) && (l == A.row-1)){
					std::cout << "error in parameter deletion. The original system's rank is 0 " << std::endl;
					ex_flag = 1;
					break;
				}
			} 
			while (A.mat[l][k] == 0);

			if (ex_flag)
				break;

			A.swapRows(k, l);
			std::swap(B.vec[l],  B.vec[k]);
		}


		for (int i = k + 1; i < A.row; i++){
			//catcher?

			//change rows::find the most [k,k]
			/*
			double maxK = 0;
			for(int r=i; r<= A.col; r++){
			if (A[r][k]>A[maxK][k])
			maxK = r;
			}
			//next do things for r

			*/
			if (A.mat[k][k] != 0){//?? catcher and change order
				double m = A.mat[i][k] / A.mat[k][k];
				for (int j = 0; j < A.col; j++){//from 0?
					A.mat[i][j] -= m*A.mat[k][j];
				}
				B.vec[i] -= m*B.vec[k]; //Change the B-vector
				std::cout << std::endl;
				A.print();
				std::cout << std::endl;
				B.print();
			}
			else{
			}
		}
	}

	if (A.mat[A.row-1][A.col-1]==0){
		std::cout << "Error in [n,n] computing. The rank of matrix is 0" << std::endl;
		ex_flag = 1;
	}

	if (!ex_flag){
		Vector X(A.row);
		X.vec[A.row - 1] = B.vec[A.row - 1] / A.mat[A.row - 1][A.col - 1];
		int i = A.row - 2;
		while (i >= 0){
			double s = 0;
			for (int j = i + 1; j < A.col; j++)
				s += A.mat[i][j] * X.vec[j];
			X.vec[i] = (B.vec[i] - s) / A.mat[i][i];
			i -= 1;
		}
		X.print();
		return X;
	}
	else{
		return{};
	}




}

//USE A FUNCTION INSTEAD OF THIS
//COMPUTING Y_HAT

//Y_hat = W*X; ???
//X is a vector for 1-dimensional objects. But for multidim onew we need MATRIX X!!!

//class Gradient{
//public:
//	core::Vector operator() (core::Vector Y, core::Vector X,  core::Vector Y_hat, core::Vector& W) const{
//		core::Vector G(W.size());
//
//		for (int i = 0; i < W.size(); i++){ 
//
//			//Count  one partial derivative
//			double s = 0;
//			for (int j = 0; j < Y.size(); j++){
//				s += (Y_hat.vec[j] - Y.vec[j])*X.vec[j];
//			}
//			G.vec[i] = s;
//		}
//
//		return G;
//		//return gradient f(X);
//	}
//
//
//};
//
//core::Vector gradient(core::Vector W, core::Vector& X){
//
//}

core::Vector gradient(core::Vector);
//Ãðàäèåíò äëÿ âåêòîðà Õ , ãðàäèåíò äëÿ ìàòðèöû ïðèçíàêîâ

//core::Vector gradientDescent(core::Vector W, core::Vector Y, core::Matrix H){
//	double eps = 0.001;
//	core::Vector E(Y.size());
//	E.init_with(eps);
//
//	double k = 0.4;
//	//ìåòîä íàèñêîð ñïóñêà äëÿ k
//	core::Vector prevW(W);
//	core::Vector Y_hat(Y.size());
//	core::Vector deltaY(Y.size());
//	int it = 0;
//	while (it <= 100){//?
//
//		core::Vector Grad(W.size());
//		Y_hat = H*W;
//		W.transpose = 1;
//		deltaY = Y - Y_hat;
//		W.transpose = 0;
//		if (deltaY<E){
//			break;
//		}		
//
//		//Grad = H*deltaY;//FOR H(X). WHATS FOR H(F(X))?
//		//Grad = 2 * H_T*(H*W - Y)
//
//		W = prevW - gradient(prevW) *k;	
//
//		it++;
//	}
//
//	return W;
//
//}


//FOR MATRIX H OF OBJECTS
//core::Vector gradientDescent(core::Vector W, core::Vector Y, core::Matrix H){
//	double eps = 0.001;
//	core::Vector E(Y.size());
//	E.init_with(eps);
//
//	int k = 0.4;
//	//ìåòîä íàèñêîð ñïóñêà äëÿ k
//	core::Vector prevW(W);
//	core::Vector Y_hat(Y.size());
//	int it = 0;
//	while (it<=100){//?
//		W = prevW - gradient(prevW) *k;
//		Y_hat = H * W;
//		if ((Y - Y_hat)<E){
//			break;
//		}
//
//		it++;
//	}
//
//	return W;
//
//}

int main(){
	std::string path = "file.txt";
	Matrix A(path);
	A.print();
	//std::cout << A[1][1] << std::endl;

	core::Vector V("file2.txt");
	V.print();

	//A.swapRows(1,2);
	//A.print();

	/*Matrix X = gauss(A, V);
	X.print();*/
	//gauss(A, V);
	
	//A + A;

	std::cin.get();

//	core::Vector V("file2.txt");
//	V.print();
//	*V[2] = 11;
//	V.print();
////	std::cout << std::endl << V[0] << std::endl;
//	//Gradient g;
//	//gradientDescent(V, g);
//
//	//ÊÂÀÄÐÀÒÛÅ ÑÊÎÁÊÈ ÒÎËÜÊÎ ÂÎÇÂÐÀÙÀÞÒ ÝËÅÌÅÍÒ ÈËÈ ÄÅËÀÞÒ ÂÎÇÌÎÆÍÛÌ ÅÃÎ ÈÇÌÅÍÅÍÈÅ??
//	std::cout << std::endl;
//	//(A*V).print();
//	//(A*A).print();
//
//	//(A.T() * V).print();
//	A + A;

	A.T().print();

	V.T().print();

	std::cin.get();
	return 0;
}


//OPERATORS!!

//×òî-òî ñ ðàâåíñòâîì íóëþ â ìåòîäå Ãàóññà
//MODIF IN GAUSS
//IN GAUSS: N=A.row-1 ??
//CHECK DIMENSION INSTEAD OF CHECKING ROW AND COL!