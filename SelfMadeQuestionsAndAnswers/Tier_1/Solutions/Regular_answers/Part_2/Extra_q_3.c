/*
	Tier 1 : Part 2	: Extra	Question 3
*/
#include<stdio.h>

int main()
{
	float pounds , kilograms ;
	
	printf("Please enter the value in pounds to be converted to kilograms\r\n");
	scanf("%f",&pounds);
	
	kilograms = pounds / 2.2 ;
	
	printf("the value in pounds %f = %f in Kilograms  \r\n",pounds,kilograms);
	
	return 0;
}