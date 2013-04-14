/*
	Tier 3 : Part 7	:	Question 3
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

typedef struct shop_parts
{
	int id_number;
	char part_name[40];
	struct shop_parts *next_struct;
}access;

int get_int();
int create_part(struct shop_parts *next);
int print_part(struct shop_parts *next);

int get_int()
{
	int user_number;
	while(scanf("%d%*c",&user_number)!=1)
	{
		fprintf(stdout,"%s","Please enter an integer value\r\n");
		fflush(stdin);
	}
	return user_number;
}


int create_part(struct shop_parts *next)//create a part with name and id number
{
	fprintf(stdout,"Please enter a part number\r\n");
	next -> id_number = get_int();
		
	fprintf(stdout,"Please enter a part name\r\n");
	fgets(next -> part_name,40,stdin);
	return 0;
}


int print_part(struct shop_parts *next)// print the name and id number
{
	fprintf(stdout,"Part_number :%d\r\n",next->id_number);
	fprintf(stdout,"Part_name :%s\r\n",next->part_name);
	return 0;
}

int main()
{
	//once typedef has been done , 
	//its not needed all the time for declaring other variables , saves space
	struct shop_parts *head;//the start of the linked list,holds the location of the first element of the list
	struct shop_parts *next;//will be used to hold the location of the next structure
	
	head = (struct shop_parts *) malloc(sizeof(struct shop_parts));
	
	if( head == NULL )
	{
		fprintf(stdout,"%d:%s\r\n",errno,strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		head;//set the next pointer to the head

		create_part(head);
		
		next = head;
		
		next = head -> next_struct =(struct shop_parts *)malloc(sizeof(struct shop_parts));// have the pointer next be allocated from the pointer in the struct in head
		// this is the first link in the list
		//best make this into a function for the future, makes life a good bit easier
		
		if(next==NULL)
		{
			fprintf(stderr,"%d:%s",errno,strerror(errno));
			exit(0);
		}
		
		create_part(next);
		next->next_struct=NULL;
		
		print_part(head);
		print_part(next);
		
		free(head);//for this sample the list is freed first from the head , dont ever do this with a linked list, as you'll
		// lose the location of the first element , therefore the rest cannot be located without it in a single linked list
		free(next);//this frees the second pointer 
		// by definition in the GNU C , free has no return value , therefore the pointers merely become "Dangling pointers" , i.e 
		// there is no way to know what exactly they will do if you were to try and use them again
	
		return 0;
	}
}