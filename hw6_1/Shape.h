#pragma once
#include <iostream>
#include <string>

using namespace std;

class Shape {
	int centerX;
	int centerY;
	string name;

public:
	virtual void draw() = 0;
	virtual double area() = 0;

	//Shape() {};
	Shape(int cx, int cy, string nm) {
		centerX = cx;
		centerY = cy;
		name = nm;
	};
	
	void print() {
		cout << name << " at ";
		cout << "(" << centerX << ", " << centerY << ")" << endl;
	};

	virtual ~Shape() = default;



};