#include <iostream>
#include <vector>
using namespace std;
void sort_up(int *arr1, int *arr2, int n) {
	int replacement;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - 1); j++) {
			if (arr1[j] > arr1[j + 1]) {
				replacement = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = replacement;
				replacement = arr2[j];
				arr2[j] = arr2[j + 1];
				arr2[j + 1] = replacement;
			}
		}
	}
}
void sort_down(int *arr1, int n) {
	int replacement;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - 1); j++) {
			if (arr1[j] < arr1[j + 1]) {
				replacement = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = replacement;
			}
		}
	}
}
void in(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << "¬ведите элемент массива: ";
		cin >> arr[i];
	}
	cout << endl;
}
void out(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void sort_num_chet(int *arr, int size) {
	int count = 0, elem = 0, chet = 0, ost = 0, sum = 0;
	int *mass = new int[size];
	for (int i = 0; i < size; i++) {
		elem = arr[i];
		while (elem > 0) {
			elem = int(elem / 10);
			count++;	
		}
		elem = arr[i];
		if (count % 2 == 0) {
			chet = 1;
			while (elem > 0) {
				ost = elem % 10;
				if (chet % 2 != 0) {
					chet++;
				}
				else {
					sum += ost;
					chet++;
				}
				elem = int(elem / 10);
			}
		}
		else {
			chet = 0;
			while (elem > 0) {
				ost = elem % 10;
				if (chet % 2 != 0) {
					chet++;
				}
				else {
					sum += ost;
					chet++;
				}
				elem = int(elem / 10);
			}
		}
		mass[i] = sum;
		count = 0;
		sum = 0;
	}
	sort_up(mass, arr, size);
	delete[] mass;
}
void last_num(int *arr, int size) {
	int numbers[10] = { 0 };
	vector <int> new_arr;
	for (int i = 0; i < size; i++) {
		numbers[arr[i] % 10]++;
	}
	for (int i = 0; i < 10; i++) {
		if (numbers[i] == 1) {
			for (int j = 0; j < size; j++) {
				if (arr[j] % 10 == i) {
					new_arr.push_back(arr[j]);
				}
			}
		}
		if (numbers[i] > 1) {
			int *idents = new int[numbers[i]];
			int counter = 0;
			for (int j = 0; j < size; j++) {
				if (arr[j] % 10 == i) {
					idents[counter] = arr[j];
					counter++;
				}
			}
			sort_down(idents, numbers[i]);
			for (int j = 0; j < numbers[i]; j++) {
				new_arr.push_back(idents[j]);
			}
			delete[] idents;
		}
	}
	for (int i = 0; i < size; i++) {
		arr[i] = new_arr[i];
	}
}
int main() {
	system("chcp 1251>nul");
	int num, size;
	int *arr = new int[1];
	while (true) {
		cout << "¬ведите номер задани€: " << endl << "1 задание" << endl << "2 задание" << endl << "3 задание" << endl << "4 задание" << endl << "5 выход" << endl;
		cin >> num;
		switch (num) {
		case 1: {
			cout << "¬ведите количество элементов массива: ";
			cin >> size;
			in(arr, size);
			break;
		}
		case 2: {
			out(arr, size);
			break;
		}
		case 3: {
			sort_num_chet(arr, size);
			break;
		}
		case 4: {
			last_num(arr, size);
			break;
		}
		case 5: {
			return 0;
			break;
		}
		default: {
			continue;
		}
		}
	}
}