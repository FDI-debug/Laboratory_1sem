#include <iostream>
#include <deque>
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

int polyndrom()
{
    deque <int> str; 
    cout << "Введите строку: ";
    string elem;
    elem = my_getline();
    int i = 0;
    while (i <= elem.length()) 
    {
        if (elem[i] == ' ') i++; 
        if (isupper(elem[i])) elem[i] = tolower(elem[i]); 
        str.push_back(elem[i]); 
        i++;
    }
    while (str.empty()) 
    {
        if (str.back() == str.front()) 
        {
            str.pop_back(); 
            str.pop_front();
        }
        else 
        {
            cout << "Не палиндром";
            return 0;
        }
    }
    cout << "Палиндром"; 
    return 0;
}

struct point 
{
    double x, y;
};

bool func(point& A, point& B, point& C) 
{
    return ((B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x) > 0);
}


void search_points()
{
    deque <int> d; 
    int min = 0; 
    int size;
    cout << "Введите количество точек: ";
    cin >> size;
    point arr[20];
    cout << "Введите точки: "; 
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }
    for (int i = 1; i < size; i++)
    {
        if (arr[i].x < arr[min].x)
        {
            min - i;
        }
    }
    point buf; 
    buf = arr[min];
    arr[min] = arr[0];
    arr[0] = buf;

    d.push_back(0);
    for (int i = 1; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (func(arr[0], arr[j], arr[min]))
            {
                min = j;
            }
        }
        buf = arr[min];
        arr[min] = arr[i];
        arr[i] = buf;
    }
    d.push_back(1);
    for (int i = 2; i < size; i++)
    {
        if (d.size() == 1) 
        {
            d.push_back(i);
        }
        else
        {
            while (d.size() > 1 && !func(arr[d[d.size() - 2]], arr[d[d.size() - 1]], arr[i])) 
            {
                d.pop_back();
            }
            d.push_back(i);
        }
    }

    for (int i = 0; i < d.size(); i++) 
    {
        cout << d[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < d.size(); i++)
    {
        cout << arr[d[i]].x << " " << arr[d[i]].y << endl;
    }
}

int main()
{   
    setlocale(LC_ALL, "Russian");
    while (true)
    {
        int N;
        cout << "1. Палиндром\n";
        cout << "2. Алгоритм Грехема\n";
        cout << "3. Выход\n";
		cout << "Введите N: ";
        cin >> N;
        switch (N)
        {
        case 1:
            polyndrom();
            break;
        case 2:
            search_points();
            break;

        case 3:
			return 0;
            break;
        default:
			cout << "Вы ввели некорректное значение.";
            break;
        }
    }
}
