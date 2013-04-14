/*
	Tier 1 : Part 2	: Extra	Question 9
*/
#include<stdio.h>

int main()
{
	float euro , dollar , conversion_constant = 1.4498 ;
	
	printf("Please enter the value in Euros to be converted \r\n");
	scanf("%f",&euro);
	
	dollar = euro * conversion_constant;
	
	printf("The conversion from %f Euros = %f$ Dollars \r\n",euro,dollar);
	
	return 0;
}