#pragma once
#include<iostream>

class matr
{
private:
	int cols, rows;
	bool* elems;
public:
	matr();
	matr(int i, int j);
	matr(int i, int j, const bool* arr);
	~matr();
	void input();
	void input(int i, int j);
	void input(int i, int j, bool* arr);
	void print();
	bool get_elem(int i, int j) { return elems[i * cols + j]; };
	bool set_elem(int i, int j, bool num);
	bool sum(const matr* mat2);
	matr sum(const bool* arr);
	bool mult(const matr* mat2);
	matr mult(const bool* arr);
	int trace();
	int det();
	void mult_by_num(bool num);
	int get_columns();
	int get_rows();
};

