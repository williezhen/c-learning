//#pragma once
//#include <iomanip>
//
//using namespace std;
//
//class Array {
//	int len;
//	int* buf;
//
//public:
//
//	Array(int new_len) : len(new_len), buf(new int[len]) {
//		fill(int());
//	}
//
//	int length() {
//		return len;
//	}
//
//	int& operator [](int index) {
//		return buf[index];
//	}
//
//	Array(const Array& a) = delete;
//
//	Array& operator = (Array& a) = delete;
//
//	void fill(int val) {
//		for (int i = 0; i < len; ++i) {
//			buf[i] = val;
//		}
//	}
//
//	void print(ostream& out) const {
//		for (int i = 0; i < len; i++) {
//			out << setw(8)
//				<< setprecision(2)
//				<< fixed
//				<< right
//				<< buf[i];
//		}
//	}
//
//	friend ostream& operator << (ostream& out, const Array& a) {
//		a.print(out);
//		return out;
//	}
//
//
//};

#pragma once
#include <iomanip>

using namespace std;

template<typename T>
class Array {
	int len;
	T* buf;
	int flag = 0;

public:

	Array() : len(0), buf(nullptr) {}

	Array(int new_len) : len(new_len), buf(new T[new_len]) {
		fill(T());
	}

	int length() {
		return len;
	}

	T& operator [](int index) {
		return buf[index];
	}

	Array(const Array& a) : len(a.len), buf(new T[a.len]) {
		for (int i = 0; i < len; i++) {
			buf[i] = a.buf[i];
		}
	}

	void fill(T val) {
		for (int i = 0; i < len; ++i) {
			buf[i] = val;
		}
	}

	void print(ostream& out) const {
		for (int i = 0; i < len; i++) {
			out << setw(8)
				<< setprecision(2)
				<< fixed
				<< right
				<< buf[i];
		}
	}

	friend ostream& operator << (ostream& out, const Array& a) {
		a.print(out);
		return out;
	}

	void delete_func() {
		if(buf)
			delete buf;
	}

	~Array() {
		cout << "array_buf : " << buf << endl;
		
		delete[] buf;
	}

};