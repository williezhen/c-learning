#include <iostream>
#include <crtdbg.h>

using namespace std;

#include "Matrix.h"

template
<typename FN, typename T>
void fill_with_array_fn(Array<T>& a, FN fn)
{
	for (int i = 0; i < a.length(); ++i)
		a[i] = fn(i);
}

template
<typename FN, typename T>
void fill_with_fn(Matrix<T>& m, FN fn)
{
	for (int i = 0; i < m.num_rows(); i++) {
		for (int j = 0; j < m.num_cols(); j++) {
			m[i][j] = fn(i, j);
		}
	}
}

void test_int_array() {
	Array<int> a{ 10 };
	auto fn = [](int i) {
		return i + 1;
	};
	a.fill(int());
	cout << a << endl;
	fill_with_array_fn(a, fn);
	cout << a << endl;
	cout << endl;
}

//void test_char_array() {
//	Array<char> a{ 26 };
//	auto fn = [](char i) {
//		return i;
//	};
//	a.fill(char());
//	cout << a << endl;
//	fill_with_array_fn(a, fn);
//	cout << a << endl;
//	cout << endl;
//}

//template <typename FN, typename T>
//void fill_with_fn(Matrix<T>& a, FN fn) {/*
//	a.fill(fn(1, 1));*/
//	for (int i = 0; i < a.num_rows(); i++) {
//		//a[i]->fill(fn(i, 1));
//		for (int j = 0; j < a.num_cols(); j++) {
//			a[i][j] = fn(i, j);
//		}
//	}
//}

void test_int_matrix() {
	Matrix<int> a{ 3, 3 };
	auto fn = [](int i, int j) {
		return i + j;
	};
	cout << "------------------" << endl;
	a.fill(int());
	cout << a << endl;
	fill_with_fn(a, fn);
	cout << a << endl;
	cout << endl;
	Matrix<int> b(a);
	cout << b << endl;
	//Matrix<int> c = a;
	//cout << c << endl;
}

void test_double_array()
{
	Array<double> a{ 10 };
	auto fn = [](int i) {return i + 1.1; };
	a.fill(double());
	cout << a << endl;
	fill_with_array_fn(a, fn);
	cout << a << endl;
	cout << endl;
}

void test_double_matrix()
{
	Matrix<double> m{ 10, 10 };
	auto fn = [](int r, int c) {return ((r + 1.0) + (c + 1.0) / 100.0); };
	m.fill(double());
	cout << m << endl;
	fill_with_fn(m, fn);
	cout << m << endl;
	cout << endl;
}

void test_char_array()
{
	Array<char> a{ 26 };
	auto fn = [](char i) {return i + 65; };
	a.fill(char());
	cout << a << endl;
	fill_with_array_fn(a, fn);
	cout << a << endl;
	cout << endl;
}

void test_char_matrix()
{
	Matrix<char> m{ 26, 26 };
	auto fn = [](char r, char c) {return ((r + 65) + (c + 65)); };
	m.fill(char());
	cout << m << endl;
	fill_with_fn(m, fn);
	cout << m << endl;
	cout << endl;
}

void test_extra() {
	Matrix<int> m{ 10,10 };
	Matrix<int> n{ m };
	cout << n << endl;

	cout << Array<int>{3} << endl;

	Array<int>* a = new Array<int>(3);
	cout << a << endl;

}

#define N 1

//void test_e

//test
	//try()
	//catch()


int main() {
	for (int i = 0; i <= N; i++) {
		test_int_array();
		test_int_matrix();
		test_char_array();
	}
	test_extra();
	_CrtDumpMemoryLeaks();
}