#include "Position.h"
#include <iostream>
using namespace std;
Position::Position()
{
	coordinate_x = 0;
	coordinate_y = 0;
}
Position::Position(int x, int y)
{

	this->coordinate_x = x;
	this->coordinate_y = y;
}
Position::~Position() {}

int Position::get_coordinate_x()
{
	return this->coordinate_x;
}

int Position::get_coordinate_y()
{
	return this->coordinate_y;
}
