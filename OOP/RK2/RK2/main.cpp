#include <iostream>
#include <string>
using namespace std;

struct spisok
{
	string str;
	spisok* next;
};
void show_spisok(spisok *spisok1)
{
	spisok* q;
	q = spisok1;
	while (q != nullptr)
	{
		cout << q->str << endl;
		q = q->next;
	}
}
int main()
{
	/*string a = "aab", b = "abb";
	bool key = false;
	key = a < b;*/
	
	string str;
	spisok *spisok1,*q,*r;
	cout << "Input string: ";
	getline(cin, str);
	if (size(str) > 0)
	{
		spisok1 = new spisok;
		int i = 0,count = 1;
		bool req = true;

		while (str[i++] == ' '); i--;
		while (str[i] != ' ' && str[i] != '\0')
		{
			spisok1->str += str[i];
			i++;
		}
		spisok1->next = nullptr;
		q = spisok1;
		for (int j = i + 1; j < size(str); j++)
		{
			if (str[j] != ' ' && str[j] != '\0')
			{
				if (req)
				{
					req = false;
					q->next = new spisok;
					q = q->next;
					q->next = nullptr;
					count++;
				}
				q->str += str[j];
			}
			else
			{
				while (str[i++] == ' '); 
				if (i<size(str))
					req = true;
			}
		}
		show_spisok(spisok1);

		//Sortirovka
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n" << "Sort:\n";
			q = spisok1;
			r = spisok1->next;
		for (int j = 0; j < count; j++)
		{
			while (r != nullptr)
			{
				if (r->str < q->str)
				{
					string vrem;
					vrem = r->str;
					r->str = q->str;
					q->str = vrem;
				}
				r = r->next;
			}
			q = q->next;
			if (q != nullptr)
				r = q->next;
		}
		show_spisok(spisok1);

		//'a' or 'm'
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n" << "'a':";
		q = spisok1;
		int k = 0;
		for (int j = 0; j < count; j++)
		{
			if (q->str[0] == 'a')
			{
				cout << '\t' << q->str; k++;
			}
			q = q->next;
		}
		if (k == 0)
			cout << " NO WORDS";
		cout << "\n'm':";
		q = spisok1;
		k = 0;
		for (int j = 0; j < count; j++)
		{
			if (q->str[0] == 'm')
			{
				cout << '\t' << q->str; k++;
			}
			q = q->next;
		}
		if (k == 0)
			cout << " NO WORDS";
		//Free memory
		q = spisok1; r = q;
		while (q!=nullptr)
		{
			q = q->next;
			delete r;
			r = q;
			count--;
		}
		cout << endl;
	}
	else cout << "Your string is empty";
	return 0;
}