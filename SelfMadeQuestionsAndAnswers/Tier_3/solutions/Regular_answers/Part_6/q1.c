/*
	Tier 3 : Part 6	:	Question 1
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int get_int();
int using_a_pointer();

int get_int()//get an int and return it
{
	int user_number;
	while(scanf("%d%*c",&user_number)!=1)
	{	
		printf("Please enter an integer\r\n");
		fflush(stdin);
	}
	return user_number;
}

int using_a_pointer()
{
	int *pointer;//create the integer pointer
	
	pointer = malloc(sizeof(int)); // malloc will alocate a single block
	//of memory the size that is placed in the function parameter
	//in this case it will simply be the size of an integer
	
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
		printf("Please enter a number \r\n");
		*pointer = get_int();
		printf("The number entered was %d \r\n",*pointer);
		return 0;
	}
}

int main()
{
	using_a_pointer();
	return 0;
}