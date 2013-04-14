/*
	Tier 1 : Part 5	:	Question 4
*/
#include<stdio.h>
#include<string.h>

int main()
{
	int loop_count , control_statement=10 ;
	
	int clean;
	
	char string[10];
	
	//Clean the string first
	for( clean =0; clean < control_statement ;clean++)
	{	string[clean] = string[clean]='\0';}
	
	printf("Please input your name  \r\n");
	scanf("%s",&string);
	
	control_statement = strlen(string);
	
	//characters are already stored as numbers , so all that is need is to print a number
	
	for( loop_count = 0 ; loop_count < control_statement ; loop_count++)
	{
		printf("%d ",string[loop_count]);
	}
	
	printf("\r\n");
	
	for( loop_count = 0 ; loop_count < control_statement ; loop_count++)
	{	
		printf("%c ",string[loop_count]);
	}
	
	return 0;
}