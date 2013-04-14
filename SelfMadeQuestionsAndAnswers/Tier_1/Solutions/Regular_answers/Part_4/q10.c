/*
	Tier 1 : Part 4	:	Question 10
*/
#include<stdio.h>

int main()
{
	int input1 , input2 ;
	int number_array[20];
	int number_array_2[20];
	
	int loop_count , control_statement = 19;
	
	for( loop_count=0; loop_count < control_statement ; loop_count++)
	{
		printf("please enter for input 1 for %d position\r\n",loop_count);
		scanf("%d",&number_array[loop_count]);
		
		loop_count++;
		
		printf("please enter for input 2 for %d position\r\n",loop_count);
		scanf("%d",&number_array[loop_count]);
	}
	
	for( loop_count=0; loop_count < control_statement ; loop_count++)
	{
		number_array_2[loop_count]=number_array[loop_count];
	}
	
	for( loop_count=0; loop_count < control_statement ; loop_count++)
	{
		printf("%d \r\n",number_array_2[loop_count]);
	}
	
	return 0;
}