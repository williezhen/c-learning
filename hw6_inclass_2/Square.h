#pragma once
#include "Rectangle.h"
#ifndef SQUARE_H
#define SQUARE_H

class Square : public Rectangle
{


public:

    Square(int cx, int cy, string nm, int s) : Rectangle(cx, cy, nm, s, s) {};

};
#endif

