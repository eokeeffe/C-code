/*
	Tier 1 : Part 8	:	Question 8
	
	The expression needs a pair of parentheis around the b||c to evaluate it to 1
	so that 1 And 1 And 0 will evaluate to zero
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 1 , b = 1, c = 0 , d=0;	
	
	printf(" expression has been evaluated = %d \r\n", a & (b || c) & d ) ;
	
	return 0;
}