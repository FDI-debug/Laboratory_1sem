#pragma once
#include "square.h"
#include "circle.h"
class circle_in_square : public square
{
public:
    circle_in_square();
    circle_in_square(int x, int  y, int dl, int r);
    ~circle_in_square();
private:
    int radius;
};

