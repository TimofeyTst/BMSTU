#include <iostream>
#include <time.h>
using namespace std;

struct el
{
	int i, j;
};
const int n = 4;
float mas[n][n]{ {1.5,7.7,3.2,8.3},{2.8,15.9,1.4,3.1},{11.1,9.5,7.6,16.8},{8.9,6.7,5.1,2.3} };

int main()
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = ((rand() % 1000)/10.0);
			cout << mas[i][j] << "   ";
		}
		cout << endl;
	}

	el max = {0, 0};
	for (int j = 0; j < n; j++)
	{
		max = { j,j };
		float vsp;
		for (int i = 0; i < n; i++)
		{
			if (mas[i][j] > mas[max.i][max.j])
			{
				max.i = i;
				max.j = j;
			}
		}
		vsp = mas[j][j];
		mas[j][j] = mas[max.i][max.j];
		mas[max.i][max.j] = vsp;
		cout << "In " << j + 1 << " stolbce addres: " << *(mas + j) + j << " Count: " << mas[j][j] << endl;
	}
	cout << "Ready: " << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << mas[i][j] << "   ";
		cout << endl;
	}
	return 0;
}