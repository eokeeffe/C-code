/*
	Tier 1 : Part 8	:	Question 4
	
	The negation is a bitwise operator , it will only work on 2 numbers 0 and 1
	so in this case if it is 1 it will be not not 1 which is evaluated as 1 but 
	because the computer only recognises 0 and 1 the rest of the numbers will simply 
	be evaluated as 1
	
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int variable_number = 0 , loop_count = 0;
	//positive numbers from 0 -> 10
	while(loop_count < 10)
	{
		printf("variable_number = %d, yet double negated = %d \r\n",variable_number, (!!variable_number) );
		loop_count++;
		variable_number++;
	}
	
	variable_number = -9 ;
	loop_count = 0;
	//negative numbers from -9 -> 0
	while(loop_count < 10)
	{
		printf("variable_number = %d, yet double negated = %d \r\n",variable_number, (!!variable_number) );
		loop_count++;
		variable_number++;
	}
	
	return 0;
}