/*
	Tier 2 : Part 3	:	Question 9
	
	Using the simple bubble sort method , the numbers are sorted into their natural
	order 
	
	The loop has to be done for each element , so the loop_count is reset to allow
	the sorting to be done to the first element in case its still bigger than the second 
	and so on
*/
#include<stdio.h>
#include<string.h>
#define LINE printf("%d is the line \r\n",__LINE__);

int main(int argc,char *argv[])
{
	char string_array[argc][20];
	char temporary_variable[20];
	
	int loop_count = 1,loop_control_statement = argc;
	int sort_control_statement=0;
	
	while(loop_count < argc)
	{
		strcpy(string_array[loop_count-1],argv[loop_count]);
		//printf("%s is %d in the array\r\n",string_array[loop_count-1],loop_count);
		loop_count++;
	}
	
	loop_count=0;
	
	while(sort_control_statement < loop_control_statement)
	{
		//printf("%c %c\r\n",string_array[loop_count][0],string_array[loop_count+1][0]);
		
		if(string_array[loop_count][0] > string_array[loop_count+1][0])
		{
			strcpy(temporary_variable , string_array[loop_count]);
			strcpy(string_array[loop_count] , string_array[loop_count+1]);
			strcpy(string_array[loop_count+1] , temporary_variable);
		
		}
		loop_count++;
		
		if(loop_count == loop_control_statement)
		{
			loop_count = 0;
			sort_control_statement++;
		}
	}
	
	
	loop_count = 0;
	while(loop_count < loop_control_statement)
	{
		printf("%s \r\n",string_array[loop_count]);
		loop_count++;
	}
	
	return 0;
}