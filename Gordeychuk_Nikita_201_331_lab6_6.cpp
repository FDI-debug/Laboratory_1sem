#include <iostream>
#include <map>
#include <string>

using namespace std;

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
	setlocale(LC_ALL, "ru");
	int buf = 0;
	double count_words = 0;
	string sentense, letter;
	map <string, int> all_letters;
	map <string, int> ::iterator finder, bufer;
	cout << "Введите предложение: ";
	sentense = my_getline();
	for (int i = 0; i < sentense.length(); i++) {
		if (sentense[i] == '.' || sentense[i] == ',' || sentense[i] == '?' || sentense[i] == '!' || sentense[i] == ',' 
			|| sentense[i] == ':' || sentense[i] == '-') {
			count_words++;
			finder = all_letters.find(letter);
			if (finder == all_letters.end()) {
				all_letters[letter] = 1;
			}
			else {
				bufer = all_letters.find(letter);
				buf = bufer->second;
				all_letters.erase(bufer);
				buf++;
				all_letters[letter] = buf;
			}
			letter = "";
		}
		else if (sentense[i] == ' ') {
			if (sentense[i - 1] == '.' || sentense[i - 1] == ',' || sentense[i - 1] == '?' || sentense[i - 1] == '!' || sentense[i - 1] == ','
				|| sentense[i - 1] == ':' || sentense[i - 1] == '-') {
				continue;
			}
			else {
				count_words++;
				finder = all_letters.find(letter);
				if (finder == all_letters.end()) {
					all_letters[letter] = 1;
				}
				else {
					bufer = all_letters.find(letter);
					buf = bufer->second;
					all_letters.erase(bufer);
					buf++;
					all_letters[letter] = buf;
				}
				letter = "";
			}
		}
		else if (sentense[i] >= 'A' && sentense[i] <= 'Z') {
				sentense[i] += 32;
				letter.push_back(sentense[i]);
			}
		else {
			letter.push_back(sentense[i]);
		}
	}
	cout << "Количество слов в тексте: " << count_words << endl;
	map <string, int> ::iterator it;
	for (it = all_letters.begin(); it != all_letters.end(); it++) {
		cout << it->first << " - " << it->second / count_words * 100 << "%" << endl;
	}
	return 0;
}