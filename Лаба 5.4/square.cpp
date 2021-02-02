#include "square.h"

square::square()
{
	this->dlinna = 0;

}

square::square(int x, int y, int dl) : Position(x, y)
{
	this->dlinna = dl;
}

square::~square() {}

int square::get_dl()
{
	return this->dlinna;
}
