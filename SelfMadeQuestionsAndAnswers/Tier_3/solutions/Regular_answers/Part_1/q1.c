/*
	Tier 3 : Part 1	:	Question 1
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

int main()
{
	int binary_number_1,binary_number_2,binary_number_3;
	
	printf("Please enter a value for A\r\n");
	while( scanf("%d",&binary_number_1) != 1)
	{
		fflush(stdin);
	}
	
	printf("Please enter a value for B\r\n");
	while( scanf("%d",&binary_number_2) != 1)
	{
		fflush(stdin);
	}
	
	printf("Please enter a value for C\r\n");
	while( scanf("%d",&binary_number_3) != 1)
	{
		fflush(stdin);
	}
	
	printf("first binary number="); 
	print_binary(binary_number_1); 
	printf("\r\n");
	
	printf("second binary number="); 
	print_binary(binary_number_2); 
	printf("\r\n");
	
	printf("third binary number="); 
	print_binary(binary_number_3); 
	printf("\r\n");
	
	return 0;
}