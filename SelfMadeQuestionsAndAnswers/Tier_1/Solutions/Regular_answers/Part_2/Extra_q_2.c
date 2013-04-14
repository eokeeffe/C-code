/*
	Tier 1 : Part 2	: Extra	Question 2
*/
#include<stdio.h>

int main()
{
	float degrees , radians , Pi = 3.1415;
	
	printf("Please enter the degrees you want converted \r\n");
	scanf("%f",&degrees);
	
	radians = (degrees * ( Pi / 180.0 ));
	
	printf("The conversion from %f is : %f \r\n",degrees,radians);
	
	return 0;
}