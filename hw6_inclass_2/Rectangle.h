#pragma once
#include "Shape.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Shape
{

    int length;
    int width;

public:

    Rectangle(int cx, int cy, string nm, int l, int w) : Shape(cx, cy, nm), length(l), width(w) {};

    void draw() {
        for (int row = 0; row < width; row += 2) {
            for (int col = 0; col < length; col++)
                cout << "*";
            cout << endl;
        }
    }

    double area() {
        return (double(length) * double(width));
    }

};
#endif

