#pragma once
#include "Shape.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle : public Shape {

    int height;
    int base;

public:

    Triangle(int cx, int cy, string nm, int h, int b) : Shape(cx, cy, nm), height(h), base(b) {};

    double area() {
        return ((base * height) / 2);
    }

    void draw() {
        int offset = max(height, base);
        for (int row = 0; row < height; row += 2) {
            for (int col = 0; col < (offset - row) / 2; col++)
                cout << " ";
            for (int i = 0; i <= row; i++)
                cout << "*";
            cout << endl;
        }
    }

};
#endif

