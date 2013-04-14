/*
	Tier 3 : Part 1	:	Question 5
	
	The function returns the right adjusted n-bit field of a that begins at position
	b 
	a >> (b+1-c) moves the desired field to the right end of the word 
	
	the reason the numbers have to unsigned is so that the sign bit wont be changed and cause problems with the bit manipulation
	
*/
#include<stdio.h>
#define SIZE_OF_BINARY_ARRAY 8

int print_binary( int number)
{
	if(number == 0)
	{
		printf("0");
		printf("0");
		printf("0");
		printf("0");
		return;
	}
	if(number > 255)
	{
		printf("Number to big for this function , only excepts 255\r\n");
		return;
	}
	else
	{
		int binary_array[SIZE_OF_BINARY_ARRAY],loop_counter=0;
		int divisor ,clean;
		
		for(clean=0;clean<SIZE_OF_BINARY_ARRAY;clean++)
		{
			binary_array[clean]='\0';
		}
		
		divisor = number;
		
		while(divisor != 0)
		{
			binary_array[loop_counter] = (divisor%2);
			divisor /= 2;
			loop_counter++;
		}
		
		while(loop_counter > 0)
		{
			printf("%d",binary_array[loop_counter]);
			loop_counter--;
		}
		if((number%2)==0)
		{
			printf("0");
		}
		if((number%2)==1)
		{
			printf("1");
		}
		return;
	}
}

int get_bits(a,b,c)	
{
	return ( (a >> (b + 1 - c) ) & ~ (~0 << c) );
}

int main()
{
	unsigned int a = 14 ,b = 4, c = 3;
	
	printf("%d \r\n", get_bits(a,b,c) );
	
	return 0;
}