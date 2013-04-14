/*
	Tier 1 : Part 6	:	Question 8
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char user_string_input[20] , user_letter_input , capture_the_rogue_character;
	int loop_counter=0 , control_statement=20 , occurence_of_user_letter=0 ;
	
	printf("Please enter a string here\r\n");
	scanf("%s",&user_string_input);
	capture_the_rogue_character = getchar();
	
	printf("please enter a letter you want to check for occurences in the string\r\n");
	scanf("%c",&user_letter_input);
	capture_the_rogue_character = getchar();
	
	while(loop_counter<control_statement)
	{
		if(user_string_input[loop_counter]==user_letter_input)
		{
			occurence_of_user_letter++;
		}
		loop_counter++;
	}
	
	printf("The letter %c occurs %d time in %s \r\n",user_letter_input,occurence_of_user_letter,user_string_input);
	
	return 0;
}