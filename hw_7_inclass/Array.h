#pragma once
#include <iomanip>
#include <string>

using namespace std;


template<typename T>
class Array {
	int len;
	T* buf;

public:
	Array():len(0), buf(nullptr) {

	}

	Array(int new_len) : len(new_len), buf(new T[len]) {
		fill(T());//int()
		//* 
		//nullptr
	}

	int length() {
		return len;
	}

	T& operator [](int index) {
		//in_bounds_Check
		//throw exception
		//return error_msg
		if (index >= 0 and index < len) {
			return buf[index];
		}
		else {
			string str = "Exception operator[]" + to_string(len) + " Out Of Range";
			throw str;
		}
		
	}

	//a.buf
	//new T
	//&
	Array(const Array& a) :len(a.len), buf(new T[a.len]) {
		for (int i = 0; i < len; i++) {
			buf[i] = a.buf[i];
		}
	}

	Array& operator = (Array& a) = delete;

	void fill(T val) {
		cout << "Array_fill: " << endl;
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

	//Array& a
	//Array a
	friend ostream& operator << (ostream& out, const Array& a) {
		cout << "1print" << endl;
		a.print(out);
		return out;
	}
	friend ostream& operator << (ostream& out, Array&& a) {
		cout << "2print" << endl;
		a.print(out);
		return out;
	}
	friend ostream& operator << (ostream& out, Array* a) {
		cout << "3print" << endl;
		a->print(out);
		return out;
	}

	~Array() {
		//new Node(nullptr)
		//new Node[5]
		delete[] buf;
	}
};