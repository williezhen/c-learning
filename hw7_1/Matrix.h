//#pragma once
//#include "Array.h"
//
//using namespace std;
//
//class Matrix {
//	int rows, cols;
//	int** matrix;
//
//public:
//
//	Matrix( int new_rows, int new_cols):rows(new_rows), cols(new_cols){}
//
//	Matrix(const Matrix& a) = delete;
//	Matrix& operator = (Matrix& a) = delete;
//
//	int num_rows() {
//		return rows;
//	}
//
//	int num_cols() {
//		return cols;
//	}
//
//	void fill(int val) {
//
//	}
//
//	int*& operator [] (int row) {
//		return matrix[row];
//	}
//
//	void print(ostream& out) {
//		
//	}
//
//	friend ostream& operator << (ostream& out, Matrix& m) {
//		out << m.num_rows();
//		return out;
//	}
//};

//<Array<T> *> matrix

#pragma once
#include "Array.h"

using namespace std;

template<typename T>
class Matrix {
	int rows, cols;
	//int** matrix;
	Array<T>** matrix;

public:

	Matrix( int new_rows, int new_cols):rows(new_rows), cols(new_cols){
		matrix = new Array<T>* [new_rows] ;
		cout << "matrix_addr : " << matrix << endl;
		for (int i = 0; i < new_rows; i++) {
			matrix[i] = new Array<T>(cols);
			cout << "array_in_matrix : " << &matrix[i] << endl;
		}
	}

	//Matrix(const Matrix& a) :rows(a.rows), cols(a.cols), matrix(new Array<T>[a.rows]) {
	//	for (int i = 0; i < rows; i++) {
	//		matrix[i] = Array<T>(cols);
	//		for (int j = 0; j < cols; j++) {
	//			matrix[i][j] = a.matrix[i][j];
	//		}
	//	}
	//}

	int num_rows() {
		return rows;
	}

	int num_cols() {
		return cols;
	}

	void fill(int val) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = val;
			}
		}
	}

	Array<T> & operator [] (int row) {
		return *matrix[row];
	}

	void print(ostream& out) {
		for (int i = 0; i < rows; i++) {
			cout << matrix[i] << endl;
			out << *matrix[i] << endl;
		}
	}

	friend ostream& operator << (ostream& out, Matrix& m) {
		m.print(out);
		return out;
	}

	~Matrix() {
		for (int i = 0; i < rows; i++) {
			cout << "array_in_matrix_addr_delete : " << &matrix[i] << endl;
			//matrix[i].delete_func();
			delete matrix[i];
		}
		cout << "matrix_addr_delete : " << matrix << endl;
		delete[] matrix;
	}
};

