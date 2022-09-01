//Вычислить: b = ( 1 + cos(y-2) ) / ( x 4 / 2 + sin2(z) )
#include <stdio.h>
#include <math.h>

int main()
{
	float b;
	int y, x, z;
	float v1, v2, v3, v4;
	printf("b = ( 1 + cos(y-2) ) / ( x 4 / 2 + sin2(z) ) \n Input x, y, z: \n");
	scanf_s("%d %d %d",&x,&y,&z);
	//v1 = cos(y - 2); v2 = pow(x, 4); v3 = pow(sin(z), 2);
	if (x == 0 && sin(z) == 0)
	{
		puts("Error! Wrong Parametres");
	}
	else
	{
		b = (1 + cos(y - 2)) / (pow(x, 4) / 2 + pow(sin(z), 2));
		// y = 92 z = 45 x = 1 we will get 1/1=1
		printf("b = %f \nx = %d,y = %d,z = %d", b, x, y, z);
	}
	return 0;
}
