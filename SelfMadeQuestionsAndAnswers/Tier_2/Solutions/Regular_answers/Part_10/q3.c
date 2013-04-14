/*
	Tier 2 : Part 10	:	Question 3
*/
#include<stdio.h>

int print_character_pointer(char *pointer);

int main()
{
	char user_character;
	char *pointer;
	
	printf("Please enter a character \r\n");
	user_character = getchar();
	
	pointer = & user_character;
	
	print_character_pointer(pointer);
	
	return 0;
}

int print_character_pointer(char *pointer)
{
	printf("%c in location %d\r\n",*pointer,pointer);
	return 0;
}