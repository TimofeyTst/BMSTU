#include "nod.h"
int nod(int x, int y)
{
	while (x != y)
		x > y ? x -= y : y -= x;
	return x;
}
