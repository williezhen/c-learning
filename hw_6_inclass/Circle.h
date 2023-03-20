#pragma once
#include <cmath>
#include "Shape.h"

using namespace std;


class Circle : public Shape {
	int radius;
	const double pi = 3.14159;

public:
	Circle(int cx, int cy, string nm, int r) : Shape(cx, cy, nm), radius(r){}


	double area() {
		return (pi * radius * radius);
	}

	void draw() {
		for (int row = -radius; row <= radius; row += 2) {
			for (int col = -radius; col <= radius; col++) {
				double distance = sqrt(col * col + row * row);
				if (distance <= radius)
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
		}
	}
};