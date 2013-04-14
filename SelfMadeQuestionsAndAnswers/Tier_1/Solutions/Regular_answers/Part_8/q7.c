/*
	Tier 1 : Part 8	:	Question 7
	
	The biggest problem here is the fact that x = 1.0 is being divided by 
	0 which cannot happen
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	float x = 1 ;
	x = x / --x;
	
	printf(" x = %f \r\n", x);
	return 0;
}