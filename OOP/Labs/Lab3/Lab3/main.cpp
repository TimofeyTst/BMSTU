/*Составить программу, которая ищет все числа в интервале от 0 до 500, 
квадраты которых являются палиндромами. 
Палиндром – это число, которое одинаково читается слева направо и справа
налево,например: 121. Вывести на экран найденные числа и их квадраты.*/
#include <stdio.h>
#include "Mod1.h"
#include <math.h>
int main()
{
	for (int i = 0; i <= 500; i++)
		if (palendrom(i*i))
			printf("%d\t %5.0f \n", i,pow(i,2));

	return 0;
}