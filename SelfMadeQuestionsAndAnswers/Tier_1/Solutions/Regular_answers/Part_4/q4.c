/*
	Tier 1 : Part 4	:	Question 4
	
	The comments should say that the character array only holds a maximum of 
	10 characters and that the other characters aren't shown as they go into 
	random memory locations
*/
#include<stdio.h>

int main()
{
	char string[10];

	printf("Please enter a word greater than 10 characters\r\n");
	scanf("%s",&string);
	
	printf("%s was the string \r\n",string);
	
	return 0;
}