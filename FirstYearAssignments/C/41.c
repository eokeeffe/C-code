/*Evan o'Keeffe
  10324289
  is a previous program only with the for loop */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SECRET "blue"
main()
{
	char g[100];
	int i=0;

	for(;i<3;)
	{
	
		printf("Please enter the word\r\n you THINK is right :)\r\n");
		gets(g);
		
		if ( strcmp( SECRET, g) == 0 )
		{
		printf("Correct guess, well done\n");
		return 0;
		}
		else{
		printf("Sorry %s is not the secret word\n");
		i++;}
		
	}
	
	printf("sorry but you have run out of tries please try again later\r\n");
	

	return 0;
}
	