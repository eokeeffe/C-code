#include<stdio.h>

int main()
{
	double x_temp;
	
	for (;;)
	{
		printf("Enter a value for x:   ");
		if (scanf("%lf", &x_temp) == 1) 
			break;
		printf("ERROR: Input real number\n");
	}
	
	return 0;
}