/*
	Tier 1 : Part 6	:	Question 5
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char user_answer[20] , catch_return_line_feed;
	int clean_array = 0;
	
	for(clean_array=0;clean_array<20;clean_array++){user_answer[clean_array]='\0';}
	
	printf("Please input either yes or no \r\n");
	scanf("%s",&user_answer);
	catch_return_line_feed = getchar();
	
	if(user_answer[0]=='y'||user_answer[0]=='Y')
	{
		printf("The first character implies you meant Yes\r\n");
	}
	
	if(strcmp(user_answer,"yes")==0||strcmp(user_answer,"Yes")==0)
	{
		printf("The string compare says you definetly said Yes\r\n");
		exit(0);
	}
	
	if(user_answer[0]=='n'||user_answer[0]=='N')
	{
		printf("The first character implies you meant No\r\n");
	}
	
	if(strcmp(user_answer,"no")==0||strcmp(user_answer,"No")==0)
	{
		printf("The string compare says you definetly said No\r\n");
		exit(0);
	}
	
	else
	{
		printf("You didn't enter a Y or N character for the string\r\n");
	}
	return 0;
}