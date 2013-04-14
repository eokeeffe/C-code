/*
	Tier 1 : Part 2	: Extra	Question 4
*/
#include<stdio.h>

int main()
{
	float inches , meters , conversion_constant = .0254;
	
	printf("Please enter the value in inches to be converted to meters\r\n");
	scanf("%f",&inches);
	
	meters = inches * conversion_constant ;
	
	printf("the value in inches %f = %f in meters  \r\n",inches,meters);
	
	return 0;
}