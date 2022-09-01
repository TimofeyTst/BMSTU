
#include <locale.h>
#include <stdio.h>
#include "nod.h"

int main()
{
	int a, b;
	setlocale(0, "russian");
	puts("Input 2 integer nums: ");
	scanf_s("%d %d",&a,&b);
	printf("Nod %d and %d = %d.\n", a, b, nod(a, b));
	test m;
	test_func();
	return 0;
}