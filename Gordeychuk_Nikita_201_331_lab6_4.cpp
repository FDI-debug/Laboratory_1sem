#include <iostream>
#include <set>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	int account;
	set <int> unique;
	set <int> non_unique;
	multiset <int> all;
	cout << "¬ведите номер аккаунта ученика, который дал ответ: ";
	cin >> account;
	unique.insert(account);
	all.insert(account);
	while (account != 0) {
		cout << "¬ведите номер аккаунта ученика, который дал ответ: ";
		cin >> account;
		if (account == 0) {
			continue;
		}
		else {
			unique.insert(account);
			all.insert(account);
		}
	}
	for (auto num : unique) {
		cout << num << ' ';
	}
	cout << endl;
	for (auto num : unique) {
		if (all.count(num) > 1) {
			non_unique.insert(num);
		}
	}
	for (auto num : non_unique) {
		unique.erase(num);
	}
	for (auto num : unique) {
		cout << num << ' ';
	}
	return 0;
}