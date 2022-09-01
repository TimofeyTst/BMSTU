#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream f;
	ofstream h, g;
	//fstream запись и чтение
	//ifstream чтение
	//ofstream запись
	f.open("first.txt", fstream::in | fstream::out | fstream::trunc);
	if (!f.is_open())
	{
		cout << "File wasn`t open";
	}
	else
	{
		cout << "input nums, for end input '#': ";
		string var;
		cin >> var;
		while (var != "#")
		{
			f << var;
			f << '\n';
			cin >> var;
		}
		h.open("krat.txt");
		g.open("notkrat.txt");
		f.seekp(0);
		f >> var;
		while (!f.eof())
		{
			int zap = stoi(var);
			if (zap % 2 == 1)
				g << var << '\n';
			else
				h << var << '\n';
			f >> var;
		}
		f.close();
		g.close();
		h.close();

	}
	return 0;
}