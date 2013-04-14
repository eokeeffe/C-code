/*
	Tier 1 : Part 5	:	Question 3
*/
#include<stdio.h>
#include<string.h>

int main()
{
	int loop_count , control_statement=10 , case_convert = 32 ;
	
	int clean;
	
	char string_lower_case[10] , string_upper_case[10];
	
	//Clean the string_lower_case first
	for( clean =0; clean < control_statement ;clean++)
	{	string_upper_case[clean] = string_lower_case[clean]='\0';}
	
	printf("Please input your name  \r\n");
	scanf("%s",&string_upper_case);
	
	control_statement = strlen(string_upper_case); // to convert only characters present in the string
	
	//convert the ascii characters from upper to lower case by adding 32 
	for( loop_count = 0 ; loop_count < control_statement ; loop_count++)
	{
		printf("%c\r\n",string_upper_case[loop_count]);
		
		string_lower_case[loop_count] = string_upper_case[loop_count] + case_convert;
		
		printf("%c\r\n",string_lower_case[loop_count]);
	}
	
	printf("This is your name in lower_case case %s \r\n",string_upper_case);
	
	return 0;
}