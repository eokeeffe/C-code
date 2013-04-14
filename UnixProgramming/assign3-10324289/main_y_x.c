#include<stdio.h>
#include "io.h"

int main()
{
	fprintf(stdout,"Square Feet to Acres Conversion\r\n");
	double x,y;
	fprintf(stdout,"Please enter the lower bound\r\n");
	x = input();
	fprintf(stdout,"Please enter the upper bound\r\n");
	y = input();

	printTableY(x,y);

	return 0;
}
