/*
	Tier 3 : Part 6	:	Question 4
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
	char *pointer[12];//create the integer pointer array
	int loop_counter=0;
	
	while(loop_counter < 12)
	{
		pointer[loop_counter] = malloc(sizeof(char)); 
		if(pointer[loop_counter]==NULL)
		{
			fprintf(stderr,"%d %s\r\n",errno,strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
			loop_counter++;
	}
	
	loop_counter=0;
	while(loop_counter < 12)
	{
		printf("Please enter a character \r\n");
		*pointer[loop_counter] = get_char();
		loop_counter++;
	}
	
	loop_counter=0;
	while(loop_counter < 12)
	{
		printf("The character entered was %c \r\n",*pointer[loop_counter]);
		loop_counter++;
	}
	
	
	return 0;
}

int main()
{
	using_a_pointer();
	return 0;
}