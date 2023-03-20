#pragma once
#include <cmath>
#include "Shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape
{

    double radius;
    double PI = 3.14159;

public:
    Circle(int cx, int cy, string nm, double r) : Shape(cx, cy, nm), radius(r) {};

    void draw() {
        for (double row = -radius; row <= radius; row += 2) {
            for (double col = -radius; col <= radius; col++) {
                double distance = sqrt(col * col + row * row);
                if (distance <= radius)
                    cout << "*";
                else
                    cout << " ";
            }

            cout << endl;
        }

    }

    double area() {
        return (PI * radius * radius);
    }

    //~Circle() {
    //    delete this;
    //}

};

#endif

