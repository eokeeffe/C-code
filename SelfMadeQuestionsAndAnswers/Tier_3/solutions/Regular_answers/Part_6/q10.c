/*
	Tier 3 : Part 6	:	Question 10
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
int starting_pointers();

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

int starting_pointers()
{
	int count=2;
	struct student *pointer;//create the character pointer array
	
	pointer = (struct student *)calloc( count , sizeof(struct student) );
	
	if( pointer == NULL )
	{
		fprintf(stderr,"%d:%s\r\n",errno,strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		int loop_counter = 0;
		while(loop_counter < count)
		{
			fprintf(stdout,"%s","Enter a name here\r\n");
			fgets( pointer[loop_counter].name , 40 ,stdin);
		
			fprintf(stdout,"%s","Enter a student number\r\n");
			pointer[loop_counter].student_number = get_int();
		
			loop_counter++;
		}
		
		loop_counter=0;
		while(loop_counter < count)
		{
			fprintf(stdout,"Struct:%d\r\n",loop_counter);
			fprintf(stdout,"Name:%s\r\n",pointer[loop_counter].name);
			fprintf(stdout,"Student Number:%d\r\n",pointer[loop_counter].student_number);
			loop_counter++;
		}
		
		int add_more=0;
		
		fprintf(stdout,"Please enter the how many more you want\r\n");
		add_more=get_int();
		add_more+=count;//original 4 + what ever was entered
		
		pointer = (struct student *)realloc( pointer , add_more ); // re allocate the pointer 
		//with the new amount allocate by add_more
		
		int total=add_more;
		
		loop_counter=count;//start from the where the last one ended
		while(loop_counter < total)
		{
			fprintf(stdout,"%s","Enter a name here\r\n");
			fgets( pointer[loop_counter].name , 40 ,stdin);
		
			fprintf(stdout,"%s","Enter a student number\r\n");
			pointer[loop_counter].student_number = get_int();
		
			loop_counter++;
		}
		
		loop_counter=0;
		while(loop_counter < total)
		{
			fprintf(stdout,"Struct:%d\r\n",loop_counter);
			fprintf(stdout,"Name:%s\r\n",pointer[loop_counter].name);
			fprintf(stdout,"Student Number:%d\r\n",pointer[loop_counter].student_number);
			loop_counter++;
		}
		
		free(pointer);
		return 0;
	}
}

int main()
{
	starting_pointers();
	return 0;
}