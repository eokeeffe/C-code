/*
	Tier 1 : Part 4	:	Question 7
	
	The comments should say that the character array only holds a maximum of 
	 characters and that the other characters aren't shown as they go into 
	the next input function , in this case its the gets that is taking the anything that isnt 
	taken in by the scanf
*/
#include<stdio.h>

int main()
{
	char string1[50];
	char string2[50];
	char return_character_capture;
	
	printf("Please enter for the scanf function \r\n");
	scanf("%s",&string1);
	
	return_character_capture = getchar();
	
	printf("Please enter for the gets function \r\n");
	gets(string2);
	
	return_character_capture = getchar();
	
	printf("The string from the scanf is %s \r\n",string1);
	
	printf("The string from the gets is %s \r\n",string2);
	
	return 0;
}