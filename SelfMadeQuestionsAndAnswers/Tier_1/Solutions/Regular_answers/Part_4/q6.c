/*
	Tier 1 : Part 4	:	Question 6
	
	The comments should say that the character array only holds a maximum of 
	 characters and that the other characters aren't shown as they go into 
	random memory locations
*/
#include<stdio.h>

int main()
{
	int loop_count = 0 , control_statement = 10;
	char array_of_strings[10][10];
	
	while( loop_count < control_statement )
	{
		printf("Please enter a string now for %d \r\n", loop_count);
		scanf("%s",&array_of_strings[loop_count][0]);
		loop_count++;
	}
	
	loop_count = 0;
	
	while( loop_count < control_statement )
	{
		printf("here is string %d : %s \r\n", loop_count , array_of_strings[ loop_count ] );
		loop_count++;
	}
	
	return 0;
}