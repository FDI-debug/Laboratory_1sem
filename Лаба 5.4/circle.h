#pragma once
#include "Position.h"
class circle : public Position
{
public:
    circle();
    circle(int x, int  y, int r);
    ~circle();
    int get_r();
private:
    int radius;
};
