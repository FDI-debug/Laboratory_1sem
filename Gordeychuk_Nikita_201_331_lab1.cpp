#include <iostream>
#include <bitset>
using namespace std;
int main() {
	cout << "1." << endl;
	cout << "Gordeychuk Nikita Aleksandrovich, 201-331" << endl;
	cout << "2." << endl;
	cout << "min int = -2147483648, max int = 2147483647, size of int = 4\n\
min unsigned int = 0, max unsigned int = 4294967295, size of unsigned int = 4\n\
min short = -32768, max short = 32767, size of short = 2\n\
min unsigned short = 0, max unsigned short = 65535, size of unsigned short = 2\n\
min long = -2147483648, max long = 2147483647, size of long = 4\n\
min long long = -9223372036854775808, max long long = 9223372036854775807, size of long long = 8\n\
min double = -9223372036854775808.0, max double = 9223372036854775807.0, size of double = 8\n\
min char = 0, max char = 255, size of char = 1\n\
min bool = 0, max bool = 255, size of bool = 1" << endl;
	cout << "3." << endl;
	int number;
	cout << "Введите число: ";
	cin >> number;
	cout << "В бинарном виде ";
	cout << bitset<16>(number) << endl;
	cout << "В шестнадцатиричном виде ";
	cout << hex << number << dec << endl;
	cout << "bool ";
	cout << bool(number) << endl;
	cout << "double ";
	cout << double(number) << endl;
	cout << "char ";
	cout << char(number) << endl;
	cout << "4." << endl;
	int a, b;
	cout << "Введите коэффициенты a * x = b: ";
	cin >> a >> b;
	cout << a << " * x = " << b << endl;
	cout << "x = " << b << " / " << a << endl;
	cout << "x = " << (double) b / a << endl;
	cout << "Ответ: " << (double) b / a << "." << endl;
	cout << "5." << endl;
	int first, last;
	cout << "Введите координаты отрезка на прямой: ";
	cin >> first >> last;
	cout << "Середина отрезка находится в точке с координатой " << (double) (first + last) / 2 << "." << endl;
}
