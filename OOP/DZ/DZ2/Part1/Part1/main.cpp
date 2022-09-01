#include <iostream>
#define work
//#define debug
using namespace std;

int max_posled(const int mas[50], int itog[50],int size)
{
	int max_v = 1, itog_v[50], max = 1, j=0;
	bool first=true; 
	itog[0] = mas[0];
	for (int i = 0; i < size-1; i++)
	{
		if (mas[i] < mas[i + 1])
		{
			if (first)
			{
				first = false;
				max_v++;
				itog_v[j++] = mas[i];
				itog_v[j++] = mas[i + 1];
			}
			else
			{
				max_v++;
				itog_v[j++] = mas[i+1];
			}
		}
		else
		{
			if (max_v > max)
			{
				max = max_v;
				for (int i = 0; i < j; i++)
				{
					itog[i] = itog_v[i];
				}
			}
			first = true;
			max_v = 1;
			j = 0;
		}
	}
	if (max_v > max)
	{
		max = max_v;
		for (int i = 0; i < j; i++)
		{
			itog[i] = itog_v[i];
		}
	}
	return max;
}

int main()
{
	char ch[11]="";
	int elems[50], i = 0, posled[50], count = 1;;
#ifdef work
	cout << "Inputs nums, count of which must be < 12. If u want input '0' write #0\n For end input #end"<< endl ;
	scanf_s("%s", ch, 10);
	while (strcmp(ch, "#end")!=0)
	{
		if (strcmp(ch, "#0") == 0)
			elems[i++] = 0;
		else if (atoi(ch)!=0)
		elems[i++] = atoi(ch);
		scanf_s("%s", ch, 10);
	}
#endif

#ifdef debug
	
	for (i = 0; i < 10; i++)
	{
		elems[i] = rand()%100;
	}
	elems[0] = 12;
	elems[1] = 51;
	elems[2] = 17;
	elems[3] = 40;
	elems[4] = 11;
	elems[5] = 1;
	elems[6] = 2;
	elems[7] = 3;
	elems[8] = 17;
	elems[9] = 0;

#endif
	cout << "You input: ";
	for (int j = 0; j < i; j++)
	{
		cout << elems[j] << " ";
	}
	count = max_posled(elems, posled, i);
	cout << "\nOutput: Count - " << count << endl;
	for (int j = 0; j < count; j++)
		cout << posled[j] << '\t';
	system("\npause");
	return 0;
}

