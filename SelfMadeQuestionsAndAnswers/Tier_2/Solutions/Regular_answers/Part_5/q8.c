/*
	Tier 2 : Part 5	:	Question 8
*/
#include <stdio.h>

int main()
{
	int x,y;
	x=7;y=5;
	
	int z = x / y; // yeah it will work but you'll miss all the figures after the decimal point
				   //meaing if this is 1.400000 , you will only get 1
	
	printf("z=%d\r\n",z);
	
	//does this solution fix the problem ?

	//Answer should be solution doesn't work as the casting cannot be done 
	//in this operation as the cast would have to be on all 3 data-types
	//if a programmer tried to compile this they would get an error
	//lvalue required at left of assignement
	
	//(float)z = x / y;
	
	return 0;
}