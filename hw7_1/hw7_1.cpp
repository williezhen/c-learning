//#include <iostream>
//
//using namespace std;
//
//#include "Array.h"
//
//template <typename FN>
//void fill_with_fn(Array& a, FN fn) {
//	for (int i = 0; i < a.length(); i++) {
//		a[i] = fn(i);
//	}
//}
//
//void test_int_array() {
//	Array a{ 10 };
//	auto fn = [](int i) {return i + 1; };
//	a.fill(int());
//	cout << a << endl;
//	fill_with_fn(a, fn);
//	cout << a << endl;
//	cout << endl;
//}
//
//#define N 1
//
//int main() {
//	for (int i = 1; i <= N; i++) {
//		test_int_array();
//	}
//}


#include <iostream>
#include <crtdbg.h>

using namespace std;

#include "Matrix.h"

template <typename FN, typename T>
void fill_arr_with_fn(Array<T>& a, FN fn) {
	for (int i = 0; i < a.length(); i++) {
		a[i] = fn(i);
	}
}


void test_int_array() {
	Array<int> a{ 10 };
	auto fn = [](int i) {return i + 1; };
	a.fill(int());
	cout << a << endl;
	fill_arr_with_fn(a, fn);
	cout << a << endl;
	cout << endl;
	//a.delete_func();
}

template <typename FN, typename T>
void fill_matrix_with_fn(Matrix<T>& m, FN fn) {
	for (int i = 0; i < m.num_rows(); i++) {
		for (int j = 0; j < m.num_cols(); j++) {
			m[i][j] = fn(i, j);
			cout << "test: " << m[i][j] << " " << &m[i] << endl;
		}
	}
}

void test_int_matrix() {
	Matrix<int> m{ 3, 3 };
	auto fn = [](int i, int j) { return i + j; };
	/*cout << fn << endl;*/
	cout << m << endl;
	fill_matrix_with_fn(m, fn);
	cout << m << endl;
}


#define N 2

int main() {
	for (int i = 1; i <= N; i++) {
		test_int_array();
		test_int_matrix();
	}
	//int* p = new int [5];
	//for (int i = 0; i < 5; i++) {
	//	cout << p++ << endl;
	//}
		//int** p = new int* [5];
		//for (int i = 0; i < 5; i++)
		//	p[i] = new int[10];
	_CrtDumpMemoryLeaks();
	return 0;
}