/*
	Tier 2 : Part 5	:	Question 7
*/
#include <stdio.h>

int main()
{
	int i= 16777217;
	
    float f = 16777217.0; 
	// with floats , the C standard sadly can allow for some
	// rounding in floating point numbers with printf
	// as you can see , this could be potentially quite annoying
	
    printf("The integer is: %i \n", i);
	
    printf("The float is:   %20f \n", f);
	
    printf("Their equality: %i \n", i == f);
	
	return 0;
}