#include <iostream>
#include <string>
#include <vector>
using namespace std;
void polyndrom(string str) {
	int len, count = 0;
	bool check = true;
	vector <char> chr_mass;
	vector <char> chr_mass_copy;
	len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == char(' ')) {
			continue;
		}
		else {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 'a' - 'A';
			}
			else if (str[i] >= '�' && str[i] <= '�') {
				str[i] += '�' - '�';
			} 
			chr_mass.push_back(str[i]);
			count++;
		}
	}
	for (int i = count - 1; i >= 0; i--) {
		chr_mass_copy.push_back(chr_mass[i]);
	}	
	for (int i = 0; i < count; i++) {
		if (char(chr_mass[i]) != char(chr_mass_copy[i])) {
			check = false;
			break;
		}
		else {
			continue;
		}
	} 
	if (check) {
		cout << "���������" << endl;
	}
	else {
		cout << "�� ���������" << endl;
	}
}
void find(string str, string substr) {
	int n_ptr = 0;
	bool found = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == substr[n_ptr]) {
			n_ptr += 1;
		}
		else {
			n_ptr = 0;
		}
		if (n_ptr >= substr.length()) {
			cout << "������� ��" << " " <<  i - substr.length() + 1 << " " << "��" << " " << i << endl;
			found = true;
			n_ptr = 0;
		}
	}
	if (found == false) {
		cout << "�� �������" << endl;
	}
}
void encrypt(string str, int rang) {
	for (auto& elem : str) {
		if (elem >= 'a' && elem <= 'z') {
			elem = ((elem - 'a' - rang) % 26) + 'a';
		}
		if (elem >= 'A' && elem <= 'Z') {
			elem = ((elem - 'A' - rang) % 26) + 'A';
		}
		if (elem >= '�' && elem <= '�') {
			elem = ((elem - '�' - rang) % 33) + '�';
		}
		if (elem >= '�' && elem <= '�') {
			elem = ((elem - '�' - rang) % 33) + 'A';
		}
	}
	cout << str << endl;
}
void ceasar(string str) {
	int shift = 0;
	cout << "������� �����: ";
	cin >> shift;
	for (auto& elem : str) {
		if (elem >= 'a' && elem <= 'z') {
			elem = ((elem - 'a' + shift) % 26) + 'a';
		}
		if (elem >= 'A' && elem <= 'Z') {
			elem = ((elem - 'A' + shift) % 26) + 'A';
		}
		if (elem >= '�' && elem <= '�') {
			elem = ((elem - '�' + shift) % 33) + '�';
		}
		if (elem >= '�' && elem <= '�') {
			elem = ((elem - '�' + shift) % 33) + 'A';
		}
	}
	cout << str << endl;
	encrypt(str, shift);
}
void text(string str) {
	bool start_finish = false, print = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '"' && start_finish == false) {
			start_finish = true;
			print = true;
			continue;
		}
		if (str[i] == '"' && start_finish == true) {
			start_finish = false;
			print = false;
			cout << " ";
			continue;
		}
		else if (print) {
			cout << str[i];
		}
		else {
			continue;
		}
	}
	cout << endl;
}

string my_getline() {
	char tmp;
	string outp;
	cin.get(tmp);
	while (tmp == '\n') { cin.get(tmp); }
	while (tmp != '\n') {
		outp.push_back(tmp);
		cin.get(tmp);
	}
	return outp;
} 
int main() {
	system("chcp 1251>nul");
	int num;
	string str;
	cout << "������� ������: ";
	getline(cin, str);
	while (true) {
		cout << "������� ����� �������: " << endl << "1 �������" << endl << "2 �������" << endl << "3 �������" << endl << "4 �������" << endl << "5 �����" << endl;
		cin >> num;
		switch (num) {
		case 1: {
			polyndrom(str);
			break;
		}
		case 2: {
			string substr;
			cout << "������� ���������: ";
            substr = my_getline();
			find(str, substr);
			break;
		}
		case 3: {
			ceasar(str);
			break;
		}
		case 4: {
			text(str);
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