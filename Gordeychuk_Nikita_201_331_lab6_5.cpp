#include <iostream>
#include <list>
#include <string>
#include <deque>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int count_students, group_number;
	bool unique_flag = true;
	string lastname;
	list <pair <int, string> > group_and_student;
	deque <int> unique_group;
	cout << "¬ведите количество учеников: ";
	cin >> count_students;
	for (int i = 0; i < count_students; i++) {
		cout << "¬ведите номер группы и фамилию ученика через пробел: ";
		cin >> group_number >> lastname;
		group_and_student.emplace_back(group_number, lastname);
	}
	for (auto tuple : group_and_student) {
		if (unique_group.empty()) {
			unique_group.push_back(tuple.first);
		}
		else {
			for (auto group : unique_group) {
				if (group == tuple.first) {
					unique_flag = false;
					break;
				}
				else {
					unique_flag = true;
				}
			}
			if (unique_flag) {
				unique_group.push_back(tuple.first);
			}
			else {
				continue;
			}
		}
	}
	for (auto group : unique_group) {
		for (auto tuple : group_and_student) {
			if (tuple.first == group) {
				cout << tuple.first << ' ' << tuple.second << endl;
			}
		}
	}
	return 0;
}