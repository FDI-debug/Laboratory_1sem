#pragma once
#include<iostream>

class matr
{
private:
	int cols, rows;
	int* elems;
public:
	matr();
	matr(const matr& other);
	~matr();
	void input();
	void print();
	int get_elem(int i, int j) { return elems[i * cols + j]; };
	int trace();
	int getcolumns();
	int getrows();
	int mult(const matr* mat2);
	void mult_by_num(int num);
	int sum(const matr* mat2);
	int set_elem(int i, int j, int num);
	friend matr operator+(const matr& mat1, const matr& mat2);
	friend matr operator-(const matr& mat1, const matr& mat2);
	friend matr operator*(const matr& mat1, const matr& mat2);
	friend matr operator*(const matr& mat1, int i);
	friend std::ostream& operator<<(std::ostream& out, const matr& matprnt);
	friend std::istream& operator>>(std::istream& in, const matr& matprnt);
	matr operator-();
};

matr operator+ (const matr& mat1, const matr& mat2);
matr operator-(const matr& mat1, const matr& mat2);
matr operator*(const matr& mat1, const matr& mat2);
matr operator*(const matr& mat1, int b);
std::ostream& operator<<(std::ostream& out, const matr& matprnt);
std::istream& operator>>(std::istream& in, const matr& matprnt);