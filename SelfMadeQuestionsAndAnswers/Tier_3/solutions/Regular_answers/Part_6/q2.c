/*
	Tier 3 : Part 6	:	Question 2
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int get_char();
int using_a_pointer();

int get_char()//get a char and return it
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
	char *pointer;//create the character pointer
	
	pointer = malloc(sizeof(char)); // malloc will alocate a single block
	//of memory the size that is placed in the function parameter
	//in this case it will simply be the size of an character
	
	// when allocating memory you have to make sure that 
	// the pointer isn't null or else the allocation has
	//failed
	if(pointer==NULL)
	{
		fprintf(stderr,"%d %s\r\n",errno,strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Please enter a character \r\n");
		*pointer = get_char();
		printf("The character entered was %c \r\n",*pointer);
		return 0;
	}
}

int main()
{
	using_a_pointer();
	return 0;
}