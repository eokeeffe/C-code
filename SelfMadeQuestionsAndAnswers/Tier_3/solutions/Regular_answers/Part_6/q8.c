/*
	Tier 3 : Part 6	:	Question 8
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

struct student
{
	char name[40];
	int student_number;
};

int get_int();
int using_a_pointer();

int get_int()
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
	struct student *pointer;//create the character pointer array
	
	pointer = malloc( sizeof(struct student) );
	
	if( pointer == NULL )
	{
		fprintf(stderr,"%d:%s\r\n",errno,strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout,"%s","Enter a name here\r\n");
		fgets( pointer->name , 40 ,stdin);
		
		fprintf(stdout,"%s","Enter a student number\r\n");
		pointer->student_number = get_int();
		
		fprintf(stdout,"Name:%s\r\n",pointer->name);
		fprintf(stdout,"Student Number:%d\r\n",pointer->student_number);
		
		free(pointer);
		pointer = NULL;
		
		if( pointer != NULL )
		{
			fprintf(stdout,"%d:%s\r\n",errno,strerror(errno));
			exit(EXIT_FAILURE);
		}
		else
			return 0;
	}
}

int main()
{
	using_a_pointer();
	return 0;
}