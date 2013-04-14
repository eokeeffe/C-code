/*
	Tier 3 : Part 6	:	Question 3
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
	int *pointer[10];//create the integer pointer array
	int loop_counter=0;
	
	while(loop_counter<10)
	{
		pointer[loop_counter] = malloc(sizeof(int)); 
		if(pointer[loop_counter]==NULL)
		{
			fprintf(stderr,"%d %s\r\n",errno,strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
			loop_counter++;
	}
	
	loop_counter=0;
	while(loop_counter<10)
	{
		printf("Please enter a number \r\n");
		*pointer[loop_counter] = get_int();
		loop_counter++;
	}
	
	loop_counter=0;
	while(loop_counter<10)
	{
		printf("The number entered was %d \r\n",*pointer[loop_counter]);
		loop_counter++;
	}
	
	
	return 0;
}

int main()
{
	using_a_pointer();
	return 0;
}