#include <iostream>
#include <string>

using namespace std;

struct student_data {
	string surname;
	string name;
	int age;
};

template <class Type>
Type _sort(Type data, int sort, int start, int finish) {
	if (sort == 1) {
		int l = start, r = finish;
		student_data piv = data[(l + r) / 2];
		while (l <= r) {
			while (data[l].surname[0] < piv.surname[0]) l++;
			while (data[r].surname[0] > piv.surname[0]) r--;
			if (l <= r) swap(data[l++], data[r--]);
		}
		if (start < r) _sort(data, 1, start, r);
		if (finish > l) _sort(data, 1, l, finish);
	}
	else if (sort == 2) {
		int l = start, r = finish;
		student_data piv = data[(l + r) / 2];
		while (l <= r) {
			while (data[l].name[0] < piv.name[0]) l++;
			while (data[r].name[0] > piv.name[0]) r--;
			if (l <= r) swap(data[l++], data[r--]);
		}
		if (start < r) _sort(data, 2, start, r);
		if (finish > l) _sort(data, 2, l, finish);
	}
	else if (sort == 3) {
		int l = start, r = finish;
		student_data piv = data[(l + r) / 2];
		while (l <= r) {
			while (data[l].age < piv.age) l++;
			while (data[r].age > piv.age) r--;
			if (l <= r) swap(data[l++], data[r--]);
		}
		if (start < r) _sort(data, 3, start, r);
		if (finish > l) _sort(data, 3, l, finish);
	}
	return data;
}

int main() {
	setlocale(LC_ALL, "ru");
	int count_students, type_sort;
	student_data student;
	cout << "¬ведите количество учеников: ";
	cin >> count_students;
	student_data *student_list = new student_data[count_students];
	for (int i = 0; i < count_students; i++) {
		cout << "¬ведите фамилию, им€ и возраст студента через пробел: ";
		cin >> student.surname >> student.name >> student.age;
		student_list[i] = student;
	}
	cout << "¬ыберите тип сортировки списка(1 - по фамилии, 2 - по имени, 3 - по возрасту): ";
	cin >> type_sort;
	switch (type_sort) {
	case 1: {
		_sort(student_list, 1, 0, count_students - 1);
		break;
	}
	case 2: {
		_sort(student_list, 2, 0, count_students - 1);
		break;
	}
	case 3: {
		_sort(student_list, 3, 0, count_students - 1);
		break;
	}
	}
	for (int i = 0; i < count_students; i++) {
		cout << student_list[i].surname << ' ' << student_list[i].name << ' ' << student_list[i].age << endl;
	}
	delete[] student_list;
	return 0;
}
