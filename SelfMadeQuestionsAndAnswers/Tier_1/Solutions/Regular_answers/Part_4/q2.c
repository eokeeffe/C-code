/*
	Tier 1 : Part 4	:	Question 2
*/
#include<stdio.h>

int main()
{
	int control_statement = 9 , loop_count = 1 , user_input = 0;
	
	int array_of_ints[10];
	
	printf("Please enter a number \r\n");
	scanf("%d", &array_of_ints[0] );
	
	while( control_statement < loop_count )
	{
		printf("user entered %d into array_of_ints[%d] \r\n",user_input,loop_count);
		
		scanf("%d", &array_of_ints[loop_count] );
		
		loop_count++;
	}
	
	
	return 0;
}