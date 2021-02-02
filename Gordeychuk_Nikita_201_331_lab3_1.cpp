#include <iostream>
using namespace std;

void bubble_sort (int *arr, int n)
{
	int replacement;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (n - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				replacement = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = replacement;
			}
		}
	}
}

	void countingSort(char* arr, int n)
	{
		int c[26] = { 0 }, j;
		for (int i = 0; i < n; i++)
		{
			j = (int) (arr[i] - 'a');
			c[j]++;
		}
		int i = 0;
		j = 0;
		while (j <= 26)
		{
			if (c[j] > 0)
			{
				arr[i] = char('a' + j);
				cout << arr[i];
				i++;
				c[j]--;
			}
			else
			{
				j++;
			}
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	void merge(int* numbers, int l, int r) {
		if (r == l) {
			return;
		}
		if (r - l == 1) {
			if (numbers[r] < numbers[l]) {
				swap(numbers[r], numbers[l]);
				return;
			}
		}
		int m = (r + l) / 2;
		merge(numbers, l, m);
		merge(numbers, m + 1, r);
		int swp[1000] = {0};
		int xl = l;
		int xr = m + 1;
		int cur = 0;
		while (r - l + 1 != cur) {
			if (xl > m) {
				swp[cur++] = numbers[xr++];
			}
			else if (xr > r) {
				swp[cur++] = numbers[xl++];
			}
			else if (numbers[xl] > numbers[xr]) {
				swp[cur++] = numbers[xr++];
			}
			else {
				swp[cur++] = numbers[xl++];
			}
		}
		for (int i = 0; i < cur; i++) {
			numbers[i + l] = swp[i];
		}
	}
int main()
{
	int choice = 0;
	while (true)
	{
		setlocale(LC_ALL, "rus");
		cout << "Что вы хотите выполнить? \n"
			<< "1. задание 1\n"
			<< "2. задание 2\n"
			<< "3. задание 3\n"
			<< "4. выход\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			int arr[1000], n;
			cout << "Введите n (не более 1000)" << endl;
			cin >> n;
			cout << "введите числа для сортировки" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			bubble_sort (arr, n);
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			break;
		}
		case 2:
		{
			int n;
			char arr[1000];
			cout << "Введите n (не более 1000)" << endl;
			cin >> n;
			cout << "введите буквы от a до z" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			countingSort(arr, n);
			cout << endl;
			break;
		}
		case 3:
		{
			int arr[1000], n;
			cout << "Введите n (не более 1000)" << endl;
			cin >> n;
			cout << "введите числа для сортировки" << endl;
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			merge(arr, 0, n - 1);
			for (int i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			break;
		}
		case 4:
		{
			return 0;
		}
		default:
		{
			continue;
		}
		}
	}
}