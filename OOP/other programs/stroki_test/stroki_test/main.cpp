#include <iostream>
#include <string.h>
using namespace std;

int a = 105;
void print();

namespace tima
{
	int a = 800;
}

int main()
{
	using namespace tima;
	int a = 17;
	a = 0;
	::a = 1;
	tima::a = 2;
	cout << "ssHello\n" << a << endl << ::a << endl << tima::a << endl;
	print();
	std::cout << "Hi\n";
	//system("echo %errorlevel%");
	return 1;
}

void print()
{
	cout << a << endl;
}
