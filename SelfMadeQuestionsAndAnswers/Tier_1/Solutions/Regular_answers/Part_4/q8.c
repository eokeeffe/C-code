/*
	Tier 1 : Part 4	:	Question 8
	
	The comments should include anything to do with the buffers and the 
	fact that the memory has been allocated but not cleared yet
	
	The characters there are from previous actions in the I/O buffer
*/
#include<stdio.h>

int main()
{
	char array_of_characters[50];
	int loop_control = 0 , control_statement = 50;
	
	while( loop_control < control_statement )
	{
		printf("%c ",array_of_characters[loop_control]);
		loop_control++;
	}
	
	return 0;
}