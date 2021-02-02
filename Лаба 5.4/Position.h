#pragma once
class Position
{
public:
	Position();
	Position(int x, int y);
	~Position();
	int get_coordinate_x();
	int get_coordinate_y();
protected:
	int coordinate_x;
	int coordinate_y;
};

