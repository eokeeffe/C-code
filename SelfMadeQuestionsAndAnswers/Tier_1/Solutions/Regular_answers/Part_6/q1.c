/*
	Tier 1 : Part 6	:	Question 1
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char guessing_character , catch_the_return_feed;
	
	printf("What is the right letter ?\r\n");
	
	while(1)
	{
		printf("Please enter the right letter\r\n");
		guessing_character = getchar();
		
		catch_the_return_feed = getchar(); //catchs the return feed when enter is pressed
		
		if(guessing_character=='a'){printf("Correct guess , well done\r\n"); exit(0);}
		else 
		{	
			printf("please try again\r\n");
		}
	}

	return 0;
}