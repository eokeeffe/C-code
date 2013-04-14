/*
	Tier 3 : Part 6	:	Question 6
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int get_char();
int using_a_pointer();

int get_char()//get an char and return it
{
	char user_character;
	while(scanf("%c%*c",&user_character)!=1)
	{	
		printf("Please enter an character\r\n");
		fflush(stdin);
	}
	return user_character;
}

int using_a_pointer()
{
	char *pointer;//create the character pointer array
	
	pointer = calloc(20,sizeof(char));
	
	if( pointer == NULL )
	{
		fprintf(stderr,"%d:%s\r\n",errno,strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout,"%s","Enter a string here\r\n");
		fgets( pointer,20,stdin);
		fprintf(stdout,"the string enetered was %s\r\n",pointer);
		
		pointer = realloc( NULL ,  40 *sizeof(char) );
		
		if( pointer == NULL )
		{
			fprintf(stderr,"%d:%s\r\n",errno,strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stdout,"%s","Enter a larger string here\r\n");
			fgets( pointer,40,stdin);
			
			fprintf(stdout,"the string enetered was %s\r\n",pointer);
			return 0;
		}
	}
}

int main()
{
	using_a_pointer();
	return 0;
}