/*
	Tier 1 : Part 5	:	Question 5
	
	The comments should notice that the scanf will accept a single word and not spaces
	The user should also notice that without any return character captures the gets 
	wont work either
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char string[20] , catch_characters[20] , catch_return_char;
	
	printf("Please enter for the scanf function \r\n");
	scanf("%s",&string);
	
	scanf("%s",&catch_characters);
	
	printf("string from scanf %s \r\n",string);
	printf("Press enter to continue\r\n");
	
	catch_return_char = getchar();
	
	printf("Please enter for the gets function \r\n");
	gets(string);
	
	printf("string from gets %s \r\n",string);
	
	return 0;
}