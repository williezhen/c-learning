#pragma once
#include "Shape.h"

using namespace std;


class Triangle : public Shape {
	int height;
	int base;

public:
	void draw() {
		int offset = max(height, base);
		for (int row = 0; row < height; row += 2) {
			for (int col = 0; col < (offset-row)/2; col++)
				cout << " ";
			for (int i = 0; i <= row; i++) {
				cout << "*";
			}
			cout << endl;
		}
	}
};