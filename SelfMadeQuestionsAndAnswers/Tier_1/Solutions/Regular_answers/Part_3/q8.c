/*
	Tier 1 : Part 3	:	Question 8
	
	answer should reflect on the way the loops work 
	
	in short while and for will evaluate before doing the statement 
	whereas do-while will do statement then evaluate
*/
#include<stdio.h>

int main()
{
	int control_statement = 3 , x = 3;
	
	while(x < control_statement)
	{
		x++;
	}
	
	printf("x after the while loop = %d \r\n",x);
	
	do
	{
		x++;
	}
	while(x < control_statement);
	
	printf("x after the do-while loop = %d \r\n",x);
	
	for( x = 0 ; x < control_statement ; x++ )
	{}
	
	printf("x after the for loop = %d \r\n",x);
	
	return 0;
}