/*
	Tier 1 : Part 7	:	Question 8
	
	The function is preforming a newton-raphson square root equation 
	that has been modified for computing
	
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double function(double number);

int main()
{
	double example1=9.00,example2=16.00,example3=25.00,example4=36.00;
	double example5=49.00,example6=64.00;
	
	printf("Here is a small list of numbers going through the function\r\n");
	printf("9 = %.1lf  \r\n",function(example1));
	printf("16 = %.1lf \r\n",function(example2));
	printf("25 = %.1lf \r\n",function(example3));
	printf("36 = %.1lf \r\n",function(example4));
	printf("49 = %.1lf \r\n",function(example5));
	printf("64 = %.1lf \r\n",function(example6));
	
	return 0;
}
double function(double number)
{
	double something=10;
	double variable_1=1,variable_2=0;
	int count;


	for(count=0;count<10;count++)
	{
		variable_2 = (.5) * ( variable_1 + ( number / variable_1) );
		variable_1 = variable_2;
	}
	
	return variable_2;
}