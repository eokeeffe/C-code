/*
	Tier 1 : Part 9	:	Question 9
	
*/
#include<stdio.h>

int clear_screen();

int main()
{
	clear_screen();
	return 0;
}

int clear_screen()
{
	int screen_lines_to_be_cleaned = 0;
	int number_of_lines = 50;
	
	while(screen_lines_to_be_cleaned < number_of_lines )
	{
		printf("\r\n");
		screen_lines_to_be_cleaned++;
	}
	return 0;
}