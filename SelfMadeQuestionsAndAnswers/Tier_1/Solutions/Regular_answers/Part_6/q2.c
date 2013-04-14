/*
	Tier 1 : Part 6	:	Question 2
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char guessing_string[20] , password_string[20] , catch_the_return_feed;
	int clean_array;
	
	//clean the arrays
	for(clean_array = 0; clean_array < 20; clean_array++)
	{
		guessing_string[clean_array]='\0';
		password_string[clean_array]='\0';
	}
	
	printf("What is the right word ?\r\n");
	
	strcpy(password_string,"password");
	
	while(1)
	{
		printf("Please enter the right password\r\n");
		scanf("%s",&guessing_string);
		catch_the_return_feed = getchar();
		
		if(strcmp(password_string,guessing_string) == 0)
		{
			printf("Correct guess , well done\r\n"); 
			exit(0);
		}
			
		else 
		{	
			printf("please try again\r\n");
		}
	}

	return 0;
}