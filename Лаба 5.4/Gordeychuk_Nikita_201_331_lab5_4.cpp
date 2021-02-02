#include <iostream>
#include "Position.h"
#include "circle.h"
#include "square.h"
#include "circle_in_square.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int x;
	cout « "input x: ";
	cin » x;
	int y;
	cout « "input y: ";
	cin » y;
	int r;
	cout « "input r: ";
	cin » r;
	int dl;
	cout « "input dl: ";
	cin » dl;
	cout « "Начальные значения " « endl;
	Position position_a(x, y);
	cout « "cordinate x =" « position_a.get_coordinate_x() « endl;
	cout « "cordinate y =" « position_a.get_coordinate_y() « endl;
	cout « "Круг " « endl;
	circle circle_a(x, y, r);
	cout « "cordinate x =" « circle_a.get_coordinate_x() « endl;
	cout « "cordinate y =" « circle_a.get_coordinate_y() « endl;
	cout « "radius =" « circle_a.get_r() « endl;
	cout « "Круг 2" « endl;
	circle circle_a2;
	cout « "cordinate x =" « circle_a2.get_coordinate_x() « endl;
	cout « "cordinate y =" « circle_a2.get_coordinate_y() « endl;
	cout « "radius =" « r « endl;
	square square_a(x, y, dl);
	cout « "Квардрат" « endl;
	cout « "cordinate x =" « circle_a.get_coordinate_x() « endl;
	cout « "cordinate y =" « circle_a.get_coordinate_y() « endl;
	cout « "dlinna =" « square_a.get_dl() « endl;
	cout « "Окружность В Квадрате" « endl;
	circle_in_square A(x, y, dl, r);
	cout « "cordinate x =" « circle_a.get_coordinate_x() « endl;
	cout « "cordinate y =" « circle_a.get_coordinate_y() « endl;
	cout « "dlinna =" « square_a.get_dl() « endl;
	cout « "radius =" « circle_a.get_r() « endl;
	return 0;
}
