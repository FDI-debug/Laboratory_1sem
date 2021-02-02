#include <iostream>
using namespace std;
int fact(int N) {
	int F = 1; 
	for(int i = 1; i <= N; i++) {
		F *= i;
	}
	return F;
}
void task1(int number) {
    for (int i = 0; i <= number; i++) {
        for (int j = 0; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
}
void task2(int n) {
    for (int k; k <= n; k++) {
        cout << fact(n) / (fact(n - k) * fact(k)) << " ";
    }
    cout << endl;
}
void task3() {
    int count, sum, num;
    while (true) {
        cout << "Введите число: ";
        cin >> num;
        if (num == 0) {
            break;
        }
        else {
            sum += num;
            count += 1;
        }
    }
    cout << sum / count << endl;
}
int main() {
    int num, n, choice = 0;
    while (true) {
        cout << "Что вы хотите выполнить?\n 1 задание \n 2 задание \n 3 задание \n 4 Выход" << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Введите длину ребра числового треугольника: ";
                cin >> num;
                task1(num);
                break;
            }
            case 2: {
                cout << "Введите коэффициент n: ";
                cin >> n;
                task2(n);
                break;
            }
            case 3: {
                task3();
                break;
            }
            case 4: {
                return 0;
                break;
            }
            
        }
    }
}