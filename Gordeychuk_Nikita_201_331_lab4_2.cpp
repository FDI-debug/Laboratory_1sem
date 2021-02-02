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
			cout << "Формат: ";
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
	cout << "Название: ";
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
	cout << "Путь: ";
	for (int i = 0; i < slash_index; i++) {
		path += file_path_full[i];
	}
	cout << path << endl;
	return string(path);
}
char file_disk(const string file_path_full) {
	cout << "Диск: " << file_path_full[0] << file_path_full[1] << endl;
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
		cout << "Не удалось открыть файл" << endl;
		return false;
	}
	if (!file_copy.is_open()) {
		cout << "Не удалось создать(открыть) копию" << endl;
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
	cout << "Введите полный путь: ";
	cin >> str;
	while (true) {
		cout << "1. Формат" << endl << "2. Название" << endl << "3. Путь" << endl << "4. Диск" << endl << "5. Сменить название" << endl << "6. Скопировать файл" << endl << "7. Выход" << endl << "Введите номер задания: ";
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
				cout << "Введите новое название файла: ";
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