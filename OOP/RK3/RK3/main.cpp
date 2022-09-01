#include <iostream>
#include "classes.h"
#include <time.h>
#include <conio.h>
using namespace std;

int main()
{
	srand(time(NULL));
	float mas_float[10];
	for (int i = 0; i < 10; i++)
	{
		mas_float[i] = (rand() % 1000) / 10;
	}
	B B(mas_float);
	C C(mas_float);
	cout << "==== Class B metod Print() ====\n";
	_getch();
	B.Print();
	cout << "\n==== Class C metod Print() ====\n";
	_getch();
	C.Print();

	return 0;
}