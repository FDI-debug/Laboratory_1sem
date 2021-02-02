#include "matr.h"

matr::matr()
{
	cols = 0;
	rows = 0;
	elems = nullptr;
}

matr::matr(const matr& other)
{
	cols = other.cols;
	rows = other.rows;
	elems = new int[cols * rows];
	for (int i = 0; i < cols * rows; i++)
		elems[i] = other.elems[i];
}

matr::~matr()
{
	if (elems != nullptr)
		delete[] elems;
}

int matr::set_elem(int i, int j, int num)
{
	if (i < rows && j < cols && i >= 0 && j >= 0)
		elems[i * cols + j] = num;
	else return false;
	return true;
}

int matr::trace()
{
	if (rows != cols || rows == 1 || cols == 1)
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

void matr::input()
{
	std::cout << "Input number of rows: ";
	std::cin >> rows;
	std::cout << "Input number of columns: ";
	std::cin >> cols;
	if (elems != nullptr)
		delete[] elems;
	elems = new int[rows * cols];
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j == i - 1 || j == i || j == i + 1)
			{
				elems[k] = (rand() % 29) - 9;
				k++;
			}
			else
			{
				elems[k] = 0;
				k++;
			}
		}
	}
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

int matr::getcolumns()
{
	return cols;
}

int matr::getrows()
{
	return rows;
}

int matr::sum(const matr* mat2)
{
	if (rows != mat2->rows || cols != mat2->cols)
		return false;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			set_elem(i, j, get_elem(i, j) + mat2->elems[i * cols + j]);
	return true;
}

int matr::mult(const matr* mat2)
{
	if (rows != mat2->rows || cols != mat2->cols)
		return false;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			set_elem(i, j, get_elem(i, j) * mat2->elems[i * cols + j]);
	return true;
}

void matr::mult_by_num(int num)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			set_elem(i, j, num);
}

matr operator+(const matr& mat1, const matr& mat2)
{
	matr res(mat1);
	if (mat1.cols == mat2.cols || mat1.rows == mat2.rows)
		for (int i = 0; i < mat1.cols * mat1.rows; i++)
		{
			res.elems[i] = mat1.elems[i] + mat2.elems[i];
		}
	return res;
}

std::ostream& operator<<(std::ostream& out, const matr& matprnt)
{
	for (int i = 0; i < matprnt.rows; i++)
	{
		for (int j = 0; j < matprnt.cols; j++)
			out << matprnt.elems[i * matprnt.cols + j] << "\t";
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, const matr& matprnt)
{
	int k = 0;
	for (int i = 0; i < matprnt.rows; i++)
	{
		for (int j = 0; j < matprnt.cols; j++)
			if (j == i - 1 || j == i || j == i + 1)
			{
				in >> matprnt.elems[i * matprnt.cols + j];
				k++;
			}
			else
			{
				matprnt.elems[k] = 0;
				k++;
			}
	}
	return in;
}

matr matr::operator-()
{
	for (int i = 0; i < cols * rows; i++)
		elems[i] = -elems[i];
	return *this;
}

matr operator*(const matr& mat1, int b)
{
	matr res(mat1);
	for (int i = 0; i < mat1.cols * mat1.rows; i++)
		res.elems[i] = mat1.elems[i] * b;
	return res;
}

matr operator-(const matr& mat1, const matr& mat2)
{
	matr res(mat1);
	if (mat1.cols == mat2.cols || mat1.rows == mat2.rows)
		for (int i = 0; i < mat1.cols * mat1.rows; i++)
		{
			res.elems[i] = mat1.elems[i] - mat2.elems[i];
		}
	return res;
}

matr operator*(const matr& mat1, const matr& mat2)
{
	matr res(mat1);
	if (mat1.cols == mat2.cols || mat1.rows == mat2.rows)
		for (int i = 0; i < mat1.cols * mat1.rows; i++)
		{
			res.elems[i] = mat1.elems[i] * mat2.elems[i];
		}
	return res;
}
