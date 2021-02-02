#include <iostream>
#include "matr.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	matr matrA, matrB;
	cout << "Ввод матрицы A" << endl;
	matrA.input();
	cout << "Ввод матрицы B" << endl;
	matrB.input();
	cout << "A=\n";
	matrA.print();
	cout << "B=\n";
	cout << matrB; 
	int i;
	cout << "Введите число\n";
	cin >> i;
	cout << "A*i\n";
	(matrA*i).print();
	cout << "-A=\n";
	-matrA;
	matrA.print();
	cout << "A=\n";
	cout << "A-B=\n";
	(matrA - matrB).print();
	cout << "A+B=\n";
	(matrA + matrB).print();
	cout << "A*B=\n";
	(matrA * matrB).print();
	cout << "Ввод А\n";
	cin >> matrA;
	cout << "A=\n";
	matrA.print();
	cout << "Rows of A: " << matrA.getrows() << "\t" << "Columns of A: " << matrA.getcolumns() << endl << "Rows of B: " << matrB.getrows() << "\t" << "Columns of B: " << matrB.getcolumns() << endl;
	cout << "(Matr Trace) A = ";
	cout << matrA.trace() << endl;
	matrA.sum(&matrB);
	cout << "(Result of sum) A =\n";
	matrA.print();
	matrA.mult(&matrB);
	cout << "(Result of mult) A =\n";
	matrA.print();
}
