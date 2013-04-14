/*Evan o'Keeffe
 10324289
 this program takes the users inputs 
 for the guessing game and passes
 it to the function guesssecretword*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define SECRET "blue"
int guesssecretword();
main()
{
	printf("SO YOU THINK YOU CAN DO THIS??\r\n");
	guesssecretword();
	exit(0);
}
guesssecretword(void)
{
	char g[100];
	int i=0;

	while(i<3)
	{
	
		printf("Please enter the word\r\n you THINK is right :)\r\n");
		gets(g);
		
		if ( strcmp( SECRET, g) == 0 )
		{
		printf("Correct guess, well done\n");
		return 0;
		}
		else
		{
		printf("Sorry %s is not the secret word\n");
		i++;
		}
	}
	printf("sorry but you have run out of tries please try again later\r\n");
	
}