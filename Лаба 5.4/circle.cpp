#include "circle.h"

circle::circle()
{
	this->coordinate_x = 3;
	this->coordinate_y = 2;
	this->radius = 0;
}

circle::circle(int x, int y, int r) : Position(x, y)
{
	this->radius = r;
}

circle::~circle() {}

int circle::get_r()
{
	return this->radius;
}
