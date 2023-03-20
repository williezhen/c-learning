#pragma once
#include <string>
#include <iostream>

using namespace std;

class Shape {
	int centerX;
	int centerY;
	string name;

public:
	
	Shape(int cx, int cy, string nm) : centerX(cx), centerY(cy), name(nm){}

	void print() {
		cout << name << " at " << "(" << centerX << ", " << centerY << ")" << endl;
	};

	virtual double area() = 0;
	virtual void draw() = 0;

	virtual ~Shape() = default;
};

