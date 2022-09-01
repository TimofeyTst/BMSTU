#include "mod1.h"
bool palendrom(int a)
{
	int c = a,b = 0;
	while (a != 0)
	{
		b = 10 * b + a % 10;
		a /= 10;
	}
	return c == b;
}