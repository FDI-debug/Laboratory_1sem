#include "circle_in_square.h"

circle_in_square::circle_in_square() : square()
{
	this->radius = 0;
}

circle_in_square::circle_in_square(int x, int y, int dl, int r) : square(x, y, dl)
{
	this->radius = r;
}

circle_in_square::~circle_in_square() {}