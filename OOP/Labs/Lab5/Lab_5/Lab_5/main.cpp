#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	char ch='a';
	char stroka[50];
	int i = 0;
	bool key1 = true, key2 = true, key3 = true;

	while ((ch= _getche()) != '\r')
	{
		if (ch!='\b')
			stroka[i++] = ch;
	}
	stroka[i] = '\0';
	cout << stroka << "\tDlina\t" << strlen(stroka)-1 << endl;
	
	for (int i = 0; i+2 < strlen(stroka); i++)
	{
		if (stroka[i] == 'a' && key1)
		{
			cout << stroka[i + 1] << '\t' << &stroka + i + 1 << endl; 
			key1 = false;
		}
		if (stroka[i] == 'c' && key2)
		{
			cout << stroka[i+1] << '\t' << 	&stroka + i + 1 << endl;
			key2 = false;
		}
		if (stroka[i] == 'd' && key3)
		{
			cout << stroka[i+1] << '\t' << &stroka + i + 1 << endl;
			key3 = false;
		}
	}
	return 0;
}