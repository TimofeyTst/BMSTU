#include <iostream>
#include <iomanip>
using namespace std;
char* s1, stroka[255]= "5.21 7.17 8.19 11.7 24.2 15.7 1.8 19.4 16.9 11.1 14.35 11.8 234.5";
struct spisok
{
	float num;
	spisok* next;
	spisok* prev;
};
spisok *dvus, *q, *dvus_new, *q2, *r,*r2;

float min(float a, float b)
{
	if (a > b)
		return b;
	else 
		return a;
}
void show (spisok *a)
{
	int i = 0;
	while (a != nullptr)
	{
		if (i % 5 == 0)
		{
			cout << setiosflags(ios::left) << endl << setw(2) << ++i << ") " << setw(10) << a->num;
			//cout << "\t\t";
			a = a->next;
		}
		else
		{
			cout << setiosflags(ios::left) << setw(2) << ++i << ") " << setw(10) << a->num;
			//cout << "\t\t";
			a = a->next;
		}
	}
}
int main()
{
	//gets_s(stroka);
	if (strcmp(stroka, "") != 0)
	{
		dvus = new spisok;
		dvus->num = strtod(stroka, &s1);
		dvus->next = nullptr;
		dvus->prev = nullptr;
		q = dvus;
		while (strcmp(s1, "") != 0)
		{
			q->next = new spisok;
			q->next->prev = q;
			q = q->next;
			q->next = nullptr;
			q->num = strtod(s1, &s1);
			/*
			if (s1 != "")
				cout << "Not end of string" << endl;
			else cout << "String is empty" << endl; 
			*/
		}
		//Working
		r = q; r2 = dvus;
		dvus_new = new spisok;
		dvus_new->prev = nullptr;
		dvus_new->next = nullptr;
		dvus_new->num = min(r2->num, r->num);
		r2 = r2->next;
		r = r->prev;
		q2 = dvus_new;
		while (r != nullptr)
		{
			q2->next = new spisok;
			q2->next->prev = q2;
			q2 = q2->next;
			q2->next = nullptr;
			q2->num = min(r2->num, r->num);
			r2 = r2->next;
			r = r->prev;
		}
		r = dvus; show(r);
		cout << endl;
		r = dvus_new; show(r);
		//Delete
		q = q->prev;
		while (q != nullptr)
		{
			delete q->next;
			q = q->prev;
		}
		delete dvus;
		q2 = q2->prev;
		while (q2 != nullptr)
		{
			delete q2->next;
			q2 = q2->prev;
		}
		delete dvus_new;
	}
	return 0;
}