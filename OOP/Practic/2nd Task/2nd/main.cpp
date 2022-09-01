#include <iostream>
#include <fstream> 
#include <algorithm>
#include <time.h> 
#include <set> 
#include <conio.h> 
#include <string>
//#define Teacher
//#define DEBUG
#define DEBUG_AFTER
#define DEBUG_CHEAT
//File format: "<English word>'\n'<Rus word>"
using namespace std;
struct slovo
{
	string str1, str2;
};
int main()
{
	string file_name = "Wordlist_5_1251.txt";
	system("chcp 1251 > nul");
	//system("chcp 1251");
#ifdef Teacher
	cout << "Input file name, standard it:  " << file_name << "\nChange it? [y/n]\t";
	char ch = _getch();
 	if ( ch == 'y' || ch == 'Y' || ch == 'н')
	{
		cout << "Input new file name: "; cin >> file_name;
	}
	else cout << "\n Using standard file name (pls don`t input 'Y' instead of 'y') \n";
#endif
#ifdef DEBUG
	cout << "\nТестирую русский язык\n";
#endif
	fstream file;
	file.open(file_name, fstream::in);
	if (!file.is_open())
	{
		cout << "File wasn`t open! Please make sure the name is: " << file_name << endl;
		system("pause");
		return -1;
	}
	else
	{
		int count_words = 0, i = 0,main_language = 2;
		slovo mas[255]; string input;
		cout << "How much words u want to test (<256): ";
		cin >> count_words;
		cout << "Choose format:\n(1)Eng - rus || (2)Rus - eng \tMy choose: ";
		cin >> main_language;
		if (count_words > 255)
			count_words = 255;
		if (main_language == 1)
			while (!file.eof())
			{
				getline(file, mas[i].str1);
				getline (file,mas[i].str2); //str1 - eng str2 - rus
				if (mas[i].str1 == "") i--;
				i++;
			}
		else while (!file.eof())
		{
			getline(file, mas[i].str2); 
			getline (file, mas[i].str1); //str1 - rus str2 - eng
			if (mas[i].str1 == "") i--;
			i++;
		}
		file.close();

		if (i < count_words)
		{
			count_words = i;
			cout << "File consist only " << count_words << " words, so let`s start with it" << endl;
		}
		//Start counting
		cout << "Press something to start or '-' for end...\n";
		cin.ignore();
		int for_rand = i, tryes = 0;
		ofstream Results;
		Results.open("Results.txt"); 
		while (_getch() != '-')
		{
			cout << "============= Progress Check ============\n";
			srand(time(NULL)); set<int>  check; int total = 0, correct = 0;
			i = rand() % count_words;
			while (total < count_words)
			{
				while (check.count(i))
					i = rand() % for_rand;
				check.insert(i);
				cout << "[" << total+1 << "/" << count_words << "] " << mas[i].str1;
#ifdef DEBUG_CHEAT
				cout << "(" << mas[i].str2 << ")";
#endif
				cout << " - ";
				getline (cin,input);
				transform(input.begin(), input.end(), input.begin(), ::tolower);
				transform(mas[i].str2.begin(), mas[i].str2.end(), mas[i].str2.begin(), ::tolower);
#ifdef DEBUG_AFTER
				cout << "Input: " << input << "\tCorrect: " << mas[i].str2 << "\n";
#endif
				if (input == mas[i].str2)
					correct++;
				else
					cout << "Mistake! Try harder\n";
				total++;
			}
			int var = correct * 100 / total;
			cout << "===> Results <====\nTotal words: " << total << "\tCorrect translated: " << correct << "\tProcent: " << var << "\n--> Your mark: ";
			Results << ++tryes << ") Total words : " << total << "\tCorrect translated : " << correct << "\tProcent : " << var << "\n-- > Your mark : ";
			if (var > 84)
			{
				cout << "5\n";
				Results << "5\n";
			}
			else if (var > 64)
			{
				cout << "4\n";
				Results << "4\n";
			}
			else if (var > 49)
			{
				cout << "3\n";
				Results << "3\n";
			}
			else {
				cout << "2\n";
				Results << "2\n";
			}
			cout << "\nEnter '-' to end test or press enter to start new Test...\n";
			
		}
		Results.close();
		return 0;
	}
	
}