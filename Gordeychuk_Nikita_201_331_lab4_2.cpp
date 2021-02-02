#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string file_format(const string file_path_full) {
	int dot_index;
	string format = "";
	for (int i = file_path_full.length() - 1; i >= 0; i--) {
		if (file_path_full[i] == '.') {
			dot_index = i;
			cout << "������: ";
			for (int j = dot_index + 1; j < file_path_full.length(); j++) {
				format += file_path_full[j];
			}
			break;
		}
	}
	cout << format;
	return string(format);
}
string file_name(const string file_path_full) {
	int slash_index = -1, dot_index = -1;
	string name = "";
	for (int i = file_path_full.length() - 1; i >= 0; i--) {
		if (file_path_full[i] == '.' && dot_index == -1) {
			dot_index = i;
		}
		else if (file_path_full[i] == '\\') {
			slash_index = i;
			break;
		}
	}
	cout << "��������: ";
	for (int i = slash_index + 1; i < dot_index; i++) {
		name += file_path_full[i];
	}
	cout << name << endl;
	return string(name);
}
string file_path(const string file_path_full) {
	int slash_index;
	string path = "";
	for (int i = file_path_full.length() - 1; i >= 0; i--) {
		if (file_path_full[i] == '\\') {
			slash_index = i;
			break;
		}
	}
	cout << "����: ";
	for (int i = 0; i < slash_index; i++) {
		path += file_path_full[i];
	}
	cout << path << endl;
	return string(path);
}
char file_disk(const string file_path_full) {
	cout << "����: " << file_path_full[0] << file_path_full[1] << endl;
	return '\n';
}
bool file_rename(string& file_path_full, string new_name) {
	string path, format;
	int slash_index = -1, dot_index = -1;
	for (int i = file_path_full.length() - 1; i >= 0; i--) {
		if (file_path_full[i] == '.' && dot_index == -1) {
			dot_index = i;
		}
		else if (file_path_full[i] == '\\') {
			slash_index = i;
			break;
		}
	}
	for (int i = 0; i < slash_index; i++) {
		path += file_path_full[i];
	}
	for (int i = dot_index + 1; i < file_path_full.length(); i++) {
		format += file_path_full[i];
	}
	file_path_full = path + '\\' + new_name + '.' + format;
	cout << file_path_full << endl;
	return 0;
} 
bool file_copy(const string file_path_full, string rename) {
	ifstream file;
	ofstream file_copy;
	int dot_index;
	string format = "", path_with_name = "";
	for (int i = file_path_full.length() - 1; i >= 0; i--) {
		if (file_path_full[i] == '.') {
			dot_index = i;
			for (int j = dot_index + 1; j < file_path_full.length(); j++) {
				format += file_path_full[j];
			}
			for (int j = 0; j < dot_index; j++) {
				path_with_name += file_path_full[j];
			}
			break;
		}
	}
	file.open(file_path_full);
	file_copy.open(path_with_name + "_copy." + format);
	if (!file.is_open()) {
		cout << "�� ������� ������� ����" << endl;
		return false;
	}
	if (!file_copy.is_open()) {
		cout << "�� ������� �������(�������) �����" << endl;
		return false;
	}
	file_copy << file.rdbuf();
	file.close();
	file_copy.close();
	return true;
}
int main() {
	system("chcp 1251 > nul");
	string str;
	int number_task;
	cout << "������� ������ ����: ";
	cin >> str;
	while (true) {
		cout << "1. ������" << endl << "2. ��������" << endl << "3. ����" << endl << "4. ����" << endl << "5. ������� ��������" << endl << "6. ����������� ����" << endl << "7. �����" << endl << "������� ����� �������: ";
		cin >> number_task;
		switch (number_task) {
			case 1: {
				file_format(str);
				cout << endl;
				break;
			}
			case 2: {
				file_name(str);
				break;
			}
			case 3: {
				file_path(str);
				break;
			}
			case 4: {
				file_disk(str);
				break;
			}
			case 5: {
				string new_name;
				cout << "������� ����� �������� �����: ";
				cin >> new_name;
				file_rename(str, new_name);
				break;
			}
			case 6: {
				file_copy(str, "_copy");
				break;
			}
			case 7: {
				return 0;
				break;
			}
			default: {
				continue;
			}
		}
	}
}



//D:\ChangZhi\Project1\Project1\input.txt