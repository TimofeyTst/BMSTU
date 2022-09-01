#include <iostream>
#include "class.h"
using namespace std;

int main()
{
	human Timofey("Starzhevsky", "Timofey", "Evgenyevich", {21, 9, 2003 } );
	driver Evgeny("Starzhevsky", "Evgeny", "Viktorovich", { 15, 4, 1976 }, { 1,1,2010 });
	Timofey.print();
	cout << endl;
	Evgeny.print();
	return 0;
};