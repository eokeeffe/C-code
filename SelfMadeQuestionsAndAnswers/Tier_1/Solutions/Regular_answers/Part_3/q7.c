/*
	Tier 1 : Part 3	:	Question 7
*/
#include<stdio.h>

int main()
{
	int control_statement = 3 , x = 0;
	
	while(x < control_statement)
	{
		x++;
	}
	
	printf("x after the while loop = %d \r\n",x);
	
	x = 0; //reset the x value
	
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