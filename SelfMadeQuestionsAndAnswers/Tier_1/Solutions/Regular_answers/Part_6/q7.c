/*
	Tier 1 : Part 6	:	Question 7
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int user_number_input ; 
	char capture_the_return_character;
	
	printf("1.Print Hello World\r\n");
	printf("2.Clear the screen\r\n");
	printf("3.Exit the program\r\n");
	printf("Please enter a number for the menu option\r\n");
	scanf("%d%*c",&user_number_input);
	
	switch(user_number_input)
	{
		case 1:
				{
					printf("Hello World\r\n\n\n\n");	
					main();
					break;
				}
		case 2:
				{
					
					int loop_counter;
					for(loop_counter=0;loop_counter<80;loop_counter++){printf("\r\n");}
					main();
					break;
				}
		case 3:
				{
					printf("Exiting program\r\n");
					exit(0);					
					break;
				}
		default:
				{
					printf("Sorry please try again\r\n");	
					main();
					break;
				}
	
	}
	return 0;
}