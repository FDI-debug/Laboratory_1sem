#pragma once
#include "Position.h"
class square : public Position
{
public:
    square();
    square(int x, int  y, int dl);
    ~square();
    int get_dl();
private:
    int dlinna;
};
