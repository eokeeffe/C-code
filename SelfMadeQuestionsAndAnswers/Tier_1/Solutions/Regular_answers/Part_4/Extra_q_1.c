/*
	Tier 1 : Part 4	:	Question 1
*/
#include<stdio.h>

int main()
{
	int user_input;
	int loop_count , control_statement;
	printf("Please input the size of the array\r\n");
	scanf("%d",&user_input);
	
	int int_array[user_input];
	
	control_statement = user_input;
	
	for(loop_count =0 ; loop_count < control_statement ; loop_count++)
	{
		printf("Please enter a number for position %d \r\n", loop_count);
		scanf("%d",&int_array[loop_count]);
	}
	
	for(loop_count =0 ; loop_count < control_statement ; loop_count++)
	{
		printf("position %d = %d\r\n", loop_count ,int_array[loop_count]);
	}
	
	return 0;
}