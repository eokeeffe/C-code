/*
	Tier 2 : Part 4	:	Question 3
	
	Factorial function 1=1 , 2=2 , 3=1x2x3=6 , 4 = 1x2x3x4 = 24 , 5 = 1x2x3x4x5 = 124
	
	The conditions are n the users number is less than 2 then return the number
	as its the same 
	
	else
		return the users number times the users number -1
	so it works backward to get the answer
*/
#include<stdio.h>

unsigned long func(unsigned long);

int main(void)
{
	unsigned long number = 0L;
	
	printf("\nEnter an integer value: ");
	scanf(" %lu", &number);
	
 	printf("\nThe answer of %lu is %lu\n", number, func(number));
 	return 0;
}

unsigned long func(unsigned long n)
{
	if(n < 2L)
	{
		return n;
	}
	else
	    {
			return n*func(n - 1L);
		}
}