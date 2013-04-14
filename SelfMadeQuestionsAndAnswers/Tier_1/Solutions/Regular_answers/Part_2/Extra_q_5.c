/*
	Tier 1 : Part 2	: Extra	Question 5
*/
#include<stdio.h>

int main()
{
	float miles , kilometers , conversion_constant = 0.621371192237;
	
	printf("Please enter the value in miles to be converted to kilometers\r\n");
	scanf("%f",&miles);
	
	kilometers = miles * conversion_constant ;
	
	printf("the value in miles %f = %f in kilometers  \r\n",miles,kilometers);
	
	return 0;
}