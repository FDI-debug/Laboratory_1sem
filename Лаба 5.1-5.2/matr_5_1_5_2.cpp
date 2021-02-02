#include "matr.h"

matr::matr()
{
	cols = 0;
	rows = 0;
	elems = nullptr;
}

matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;
}

matr::matr(int i, int j)
{
	cols = i;
	rows = j;
	elems = new bool[cols * rows];
}

matr::matr(int i, int j, const bool* arr)
{
	cols = i;
	rows = j;
	elems = new bool[cols * rows];
	for (int i = 0; i < cols * rows; i++)
		elems[i] = arr[i];
}

void matr::input()
{
	std::cout << "Input number of rows: ";
	std::cin >> rows;
	std::cout << "Input number of columns: ";
	std::cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new bool[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		//std::cin >> elems[i];
		elems[i] = i * 37 % 2;
}

void matr::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			std::cout << get_elem(i, j) << "\t";
		std::cout << std::endl;
	}
}

bool matr::set_elem(int i, int j, bool num)
{
	if (i < rows && j < cols && i >= 0 && j >= 0)
		elems[i * cols + j] = num;
	else return false;
	return true;
}

bool matr::sum(const matr* mat2)
{
	if (rows != mat2->rows || cols != mat2->cols)
		return false;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			set_elem(i, j, get_elem(i, j) + mat2->elems[i*cols+j]);
	return true;
}

matr matr::sum(const bool* arr)
{
	matr matr_res(rows, cols);
	for (int i = 0; i < rows * cols; i++)
		matr_res.elems[i] = (arr[i] != this->elems[i]);
	return  matr(rows, cols, matr_res.elems);
}

bool matr::mult(const matr* mat2)
{
	if (rows != mat2->rows || cols != mat2->cols)
		return false;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			set_elem(i, j, get_elem(i, j) * mat2->elems[i * cols + j]);
	return true;
}

matr matr::mult(const bool* arr)
{
	matr matr_res(rows, cols);
	for (int i = 0; i < rows * cols; i++)
		matr_res.elems[i] = (arr[i] * this->elems[i]);
	return matr(rows, cols, matr_res.elems);
}

void matr::input(int i, int j)
{
	cols = i;
	rows = j;
	if (elems != nullptr)
		delete[] elems;
	elems = new bool[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		//std::cin >> elems[i];
		elems[i] = i * 37 % 2;
}

void matr::input(int i, int j, bool* arr)
{
	cols = i;
	rows = j;
	if (elems != nullptr)
		delete[] elems;
	elems = new bool[rows * cols];
	for (int i = 0; i < rows * cols; i++)
		elems[i] = arr[i];
}

int matr::trace()
{
	if (rows != cols || rows==1 || cols==1)
	{
		std::cout << "Это не квадратная матрица";
		return 0;
	}
	int sum = 0;
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == j)
			{
				sum += elems[k];
				k++;
			}
			else
			{
				k++;
			}
		}
	}
	return sum;
}

int matr::det()
{
	if (rows != cols)
	{
		std::cout << "Это не квадратная матрица";
		return 0;
	}
	if (rows == 1)
		return elems[1, 1];
	else if (rows == 2)
		return ((elems[1, 1] + elems[2, 2]) - (elems[1, 2] + elems[2, 1]));
	else if (rows == 3)
		return ((elems[1, 1] * elems[2, 2] * elems[3, 3] + elems[1, 2] * elems[2, 3] * elems[3, 1] + elems[1, 3] * elems[2, 1] * elems[3, 2]) - (elems[1, 3] * elems[2, 2] * elems[3, 1] + elems[1, 1] * elems[2, 3] * elems[3, 2] + elems[1, 2] * elems[2, 1] * elems[3, 3]));
	else
	{
		std::cout << "Если 4 и больше не сделал :D" << std::endl;
		return 0;
	}
}

void matr::mult_by_num(bool num)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			set_elem(i, j, num);
}

int matr::get_columns()
{
	std::cout << cols;
	return 0;
}

int matr::get_rows()
{
	std::cout << rows;
	return 0;
}
