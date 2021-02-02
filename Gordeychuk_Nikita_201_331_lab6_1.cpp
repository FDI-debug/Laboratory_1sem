#include <iostream>
#include <string> 
#include <stack> 

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	stack <char> stack;
	string str;
	cout << "Введите строку: ";
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			stack.push(str[i]);
		}
		if (str[i] == ')' && !stack.empty())
		{
			if (stack.top() == '(')
				stack.pop();
			else
			{
				cout << "Неверно";
				stack.pop();
				return 0;
			}
		}
		if (str[i] == ']' && !stack.empty())
		{
			if (stack.top() == '[')
				stack.pop();
			else
			{
				cout << "Неверно";
				stack.pop();
				return 0;
			}
		}
		if (str[i] == '}' && !stack.empty())
		{
			if (stack.top() == '{')
				stack.pop();
			else
			{
				cout << "Неверно";
				stack.pop();
				return 0;
			}
		}
	}
	if (stack.empty())
		cout << "Верно";
	else cout << "Стек пуст";
	return 0;
}

