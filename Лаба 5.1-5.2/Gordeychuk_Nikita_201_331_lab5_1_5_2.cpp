#include <iostream>
#include "matr.h"
#include <string>
using namespace std;
string str;
int main()
{
	setlocale(LC_ALL, "rus");
	//Первая лабораторная
	matr matrA, matrB;
	matrA.input();
	matrB.input();
	cout << "A=\n";
	matrA.print();
	cout << "B=\n";
	matrB.print();
	cout << "Rows of A: ";
	matrA.get_rows();
	cout << "\t" << "Columns of A: ";
	matrA.get_columns();
	cout << endl << "Rows of B: ";
	matrB.get_rows();
	cout << "\t" << "Columns of B: ";
	matrB.get_columns();
	cout << endl;
	matrA.sum(&matrB);
	cout << "(Result of sum) A =\n";
	matrA.print();
	matrA.mult(&matrB);
	cout << "(Result of mult) A =\n";
	matrA.print();
	bool num;
	cin >> num;
	matrA.mult_by_num(num);
	cout << "(Result of mult by num) A =\n";
	matrA.print();
	cout << "(Matr Trace) A = ";
	cout << matrA.trace() << endl;
	//2 лабораторная
	bool arr[12] = {0,0,1,1,1,0,0,0,0,1,1,1};
	matr matrC(4,4);
	cout << "Rows of C: ";
	matrC.get_rows();
	cout << "\t" << "Columns of C: ";
	matrC.get_columns();
	cout << endl;
	matrC.input(4,4);
	cout << "C: \n";
	matrC.print();
	cout << "Result of sum:\n";
	matrC.sum(arr).print();
	cout << "Result of mult:\n";
	matrC.mult(arr).print();
	matr matrD(4, 3, arr);
	cout << "Rows of D: ";
	matrD.get_rows();
	cout << "\t" << "Columns of D: ";
	matrD.get_columns();
	matrD.input(4,3);
	cout << "\n";
	cout << "D=\n";
	matrD.print();
	matrD.input(4, 3, arr);
	cout << "D=\n";
	matrD.print();
}
