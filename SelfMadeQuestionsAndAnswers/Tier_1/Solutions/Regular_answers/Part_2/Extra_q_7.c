/*
	Tier 1 : Part 2	: Extra	Question 7
*/
#include<stdio.h>

int main()
{
	float radius , diameter , Pi = 3.1415 , circumference;
	
	printf("Please enter the radius \r\n");
	scanf("%f",&radius);
	
	diameter = radius * radius ;
	
	circumference = Pi * diameter ;
	
	return 0;
}