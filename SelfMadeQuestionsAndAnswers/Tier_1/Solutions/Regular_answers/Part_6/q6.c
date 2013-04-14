/*
	Tier 1 : Part 6	:	Question 6
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int user_number_input ; 
	char capture_the_return_character;
	
	printf("Please enter an amount in cents\r\n");
	scanf("%d%*c",&user_number_input);
	
	switch(user_number_input)
	{
		case 1:
				{
					printf("1 cent coin exists\r\n");	
					break;
				}
		case 2:
				{
					printf("2 cent coin exists\r\n");	
					break;
				}
		case 5:
				{
					printf("5 cent coin exists\r\n");	
					break;
				}
		case 10:
				{
					printf("10 cent coin exists\r\n");	
					break;
				}
		case 20:
				{
					printf("20 cent coin exists\r\n");	
					break;
				}
		case 50:
				{
					printf("50 cent coin exists\r\n");	
					break;
				}
		case 100:
				{
					printf("1 euro coin exists\r\n");	
					break;
				}
		case 200:
				{
					printf("2 euro coin exists\r\n");	
					break;
				}
		default:
				{
					printf("Cent/Euro coin doesn't exist\r\n");	
					break;
				}
	
	}
	return 0;
}