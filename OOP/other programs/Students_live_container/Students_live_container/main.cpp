#include <iostream>
#include "class.h"
using namespace std;
void show (student *fam)
{
	static int i = 1;
	cout << i++ << ") ";
	fam->print();
}
void payment(student* fam)
{
	fam->get_money();
}
int main()
{
	company_students stavropol;
	string name="Azamat";
	float scholarship_$=50,total_$=500, var = 0;
	int cause = 1;
	student* fam = new student ();
	cout << "MENU: 1 - from MGTU, 2 - from STGAU, 3 - erase, 0 - cancel\n";
	while (cause != 0)
	{
		cout << "Menu: ";
		cin >> cause;
		if (cause)
		{
			cout << "Input name | scholarship | total in $: ";
			cin >> name >> scholarship_$ >> total_$;
			switch (cause)
			{
			case 1: {cout << "Input investments in % per month: "; cin >> var; fam = new student_mgtu(name, scholarship_$, total_$, var); } break;
			case 2: {cout << "Input spending per month: "; cin >> var; fam = new student_stgau(name, scholarship_$, total_$, var); } break;
			case 3: continue; break;
			default: { cause = 0; }
				   break;
			}
			stavropol.addte(fam);
		}
	}
	cout << "\nAll list:\n";
	stavropol.foreach(show);
	cout << "\nAfter getting:\n";
	stavropol.foreach(payment);

	stavropol.foreach(show);
	cout << "\nDestructors:\n";
	return 0;
}