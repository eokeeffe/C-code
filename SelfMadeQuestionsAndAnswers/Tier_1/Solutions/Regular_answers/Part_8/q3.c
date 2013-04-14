/*
	Tier 1 : Part 8	:	Question 3
	
	The order in this case is the () characters 
	then the casting (int) and sizeof(int) operators
	Then the multiplication is done
	
	The very last thing is the assignement += is the last operator to be 
	evaluated
	
	The operators are arranged in such a way as to give the programmer as close to 
	mathematical precendence and logical precedence in real life as possible
	
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int z = 0 ;
	float f = 2.0;
	
	z += (int)(f)*(sizeof(z));
	
	printf("%d is the answer\r\n",z);
	return 0;
}