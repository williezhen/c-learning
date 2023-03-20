#pragma once
#include "Shape.h"

using namespace std;

class Rectangle : public Shape {
protected:
	int width;
	int length;


public:
	Rectangle(int cx, int cy, string nm, int w, int l) : Shape(cx, cy, nm), width(w), length(l) {}

	double area() {
		return (width * length);
	}

	void draw() {
		for (int row = 0; row < width; row += 2) {
			for (int col = 0; col < length; col++) {
				cout << "*";
			}
			cout << endl;
		}
	}
};