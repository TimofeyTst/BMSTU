#include <iostream>
using namespace std;

int main()
{
	int a = 9; double c = 5.7;
	void *b = &c;
	const int* point_1 = &a;
	double* const point_2 = &c;
	int *point_3 = &a;
	cout << "Void how float: " << b << "\t" << *static_cast<double*>(b) << endl << endl;
	// why it isnt work? *static_cast<int*>(b) = a;
	b = &a;
	cout << "Void how float: " << b << "\t" <<  *static_cast<int*>(b) << endl << endl;
	//point_1 = (int*)(b);
	*point_2+=1;
	// Error point_2 = &c;
	// Error (* point_1)+=1; 
	// Error last operate *point_2 += 1; a++; point_2 = point_1;
	cout << "Point_1:\t" << point_1 << "\t" << *point_1 << endl;
	cout << "Point_2:\t" << point_2 << "\t" << *point_2 << endl;
	cout << "Point_3:\t" << point_3 << "\t" << *point_3 << endl;
	cout << "////////////////////////////* Hard not using massive *///////////////////////////////"<< endl;
	int m[] = { 1,2,3,4 };
	int* pointer[] = {m+3,m+2,m+1,m};
	int* point_test = m + 3;
	//pointer++; 
	point_test++;
	if (pointer[1][-1] == m[1])
		cout << "Correctly!";
	else cout << "Stupid...";
	cout << endl;
	cout << "////////////////////////////* Now turn for Strings.. *///////////////////////////////" << endl << endl;
	return 0;
}