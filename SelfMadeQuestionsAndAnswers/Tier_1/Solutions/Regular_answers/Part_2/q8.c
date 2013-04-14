/*
	Tier 1 : Part 2	:	Question 8
*/
#include<stdio.h>

int main()
{
	float Fahrenheit , Celsius , equation_constant = 32.0 ;
	
	printf("Please enter the temperature in Celsius \r\n");
	scanf("%f",&Celsius);
	
	Fahrenheit = Celsius * (9/5) * equation_constant ;
	
	printf("The temperature in Celsius = %f \r\n",Celsius);
	printf("The temperature in Fahrenheit = %f \r\n", Fahrenheit);
	
	return 0;
}