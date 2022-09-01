#include <iostream>
#include <string>
using namespace std;

bool is_hissing(const char ch)
{
	if (ch == 'æ' || ch == 'ø' || ch == '÷' || ch == 'ù')
		return true;
	else 
		return false;
}
string correct(const string str)
{
	int j = 0,size = str.length();
	string correct;
	for (int k = 0; k <= size; k++)
	{
		if (str[k] == ' ' || str[k] == '\0')
		{
			while (j < k - 4)
			{
				correct += str[j];
				j++;
			}
			if (is_hissing(str[j-1]))
				correct += 'à';
			else
				correct += 'ÿ';

			correct += 'ò';
			correct += 'à';
			correct += ' ';
			j += 5;
		}
	}
	return correct;
}
int main()
{
	system("chcp 1251 > nul");
	string str, mas[20], correct_mas[20];
	int i = 0;
	cout << "Äëÿ îêîí÷àíèÿ ââîäà ââåäèòå ïóñòóþ ñòðîêó\nÂâåäèòå ñòðîêó: ";
	getline (cin, str);
	while (size(str) > 1 && i<21)
	{
		mas[i++] = str;
		cout << "Ñëåäóþùàÿ èëè ýíòåð: ";
		getline (cin,str);
	}

	//cout << mas[0][size(mas[0])] << "\t" << /*mas[0][size(mas[0])+1] <<*/ endl;
	for (int j = 0; j < i; j++)
	{
		correct_mas[j] = correct(mas[j]);
	}
	
	cout << "Âûâîä: "<<endl;
	for (int j = 0; j < i; j++)
	{
		cout << correct_mas[j] << endl;
	}
	return 0;
}	