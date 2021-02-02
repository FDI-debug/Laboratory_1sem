#include <iostream>
#include <queue>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	queue <int> q;
	int count_numbers, it_is_time_to_STOP = 0, now_num, count_5 = 0, count_3 = 0, count_2 = 0;
	cout << "¬ведите количество чисел: ";
	cin >> count_numbers;
	for (int i = 2; i <= count_numbers * 10; i++) {
		q.push(i);
	}
	while (it_is_time_to_STOP < count_numbers) {
		count_2 = 0;
		count_3 = 0;
		count_5 = 0;
		now_num = q.front();
		while (now_num % 2 == 0 && now_num > 1) {
			count_2++;
			now_num /= 2;
		}
		while (now_num % 3 == 0 && now_num > 1) {
			count_3++;
			now_num /= 3;
		}
		while (now_num % 5 == 0 && now_num > 1) {
			count_5++;
			now_num /= 5;
		}
		if (now_num == 1) {
			cout << q.front() << " = " << "2^" << count_2 << " * " << "3^" << count_3 << " * " << "5^" << count_5 << endl;
			q.pop();
			it_is_time_to_STOP++;
		}
		else {
			q.pop();
		}	
	}
	return 0;
}