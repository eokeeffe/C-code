/*
	Tier 3 : Part 7	:	Question 5
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//macro's for various debugging routines
#define PART_EXISTS fprintf(stdout," part already exists , returning to options menu\r\n");
#define NPARTS_EXISTS fprintf(stdout,"part doesn't exist , returning to options menu\r\n");
#define MEMORY_ERROR fprintf(stdout,"Memory allocation failed\r\n");
#define DYANMIC_MEMORY_ERROR fprintf(stdout,"Memory de-allocation failed at %d in %s\r\n",__LINE__,__FILE__);
#define LINE fprintf(stdout,"%d in %s\r\n",__LINE__,__FILE__);
#define NOLIST fprintf(stdout,"No list has been located\r\n");
#define HEAD fprintf(stdout,"%s is the head at line %d\r\n",head->new_part_idt_name,__LINE__);
//self referential structure that is used for this singly linked list

struct shop_parts 
{
   char part_name[40];
   int part_id;//new_part_idt ber
   struct shop_parts *next;
};
typedef struct shop_parts item;
item *head;//head of the linked list

int get_int();//return the integer entered by the user
int create_list();//create a list
int append_node(char* new_new_part_idt,int new_part_id);//append a new_part_idt to the ber
int make_head_node(char* new_new_part_idt,int new_part_id);//create a new node in the list
int add_new_part_idt(item * head);//the add new_new_part_idt function that uses the make_node
int options();//options menu for the program
int wait_for_user();//wait for the user to input something before continueing
int print_list(item * head);//print the list out
int end_all(item * head);//de-allocate all the memory if needed and then end the program

int get_int()
{
	int user_number;
	while(scanf("%d%*c",&user_number)!=1)
	{
		fprintf(stderr,"Please enter an integer\r\n");
		fflush(stdin);
	}
	return user_number;
}

int options()
{
	int user_number = 0;
	
	fprintf(stdout,"\n\n\n");
	fprintf(stdout,"Please enter a ber for the option\r\n");
	fprintf(stdout,"1.create the list\r\n");
	fprintf(stdout,"2.add a part\r\n");
	fprintf(stdout,"3.print the list\r\n");
	fprintf(stdout,"4.exit\r\n");
	
	user_number = get_int();
	if(user_number == 1)
	{
		create_list();
	}
	if(user_number == 2)
	{
		add_part(head);
	}
	if(user_number == 3)
	{
		print_list(head);
	}
	if(user_number == 4)
	{
		end_all(head);
	}
	else
	{
		fprintf(stdout,"Please enter a valid option\r\n");
		options();
	}
}

int wait_for_user()
{
	fflush(stdin);
	char dummy[50];
	fprintf(stdout,"Press enter\r\n");
	fgets(dummy,50,stdin);
	fflush(stdin);
}

int end_all(item * head)
{
	item *temporary;
	temporary = head;
	if(head==NULL)
	{
		fprintf(stdout,"Thank you for using linked list V1.0\r\n");
		exit(0);
	}
	while(temporary->next) 
	{
		temporary = temporary->next ;//take all elements except the head and de-allocate first or the pointers to the will be lost
		free(temporary);
	}
	free(head);//after they are finished free the head to de-allocate the last part of the list
	
	fprintf(stdout,"Thank you for using linked list V1.0\r\n");
	
	exit(0);
}

int append_node(char* new_part,int new_part_id)
{
	//HEAD
	item *temporary; 
	
	temporary = head;
	
	if(temporary==NULL)
	{
		NOLIST
	}
	else
	{
		while(temporary->next)
		{
			if( strcmp(temporary -> part_name , new_part)==0)
			{
				PART_EXISTS 
				wait_for_user(); 
				options();
			}
			if( temporary -> part_id ==new_part_id )
			{
				PART_EXISTS 
				wait_for_user(); 
				options();
			}
			else 
			{
				temporary = temporary -> next;
			}
		}
		temporary -> next = (item *)malloc(sizeof(item));//take the null element and append the new new_part
		
		strcpy(temporary->next->part_name,new_part);
		temporary->next-> part_id =new_part_id;
		temporary->next->next=NULL;//make the tail null again
	}
	//HEAD
}

int add_part(item * head)
{
	char new_part[50];
	int new_part_id;
	
	fprintf(stdout,"Please enter a new new_part\r\n");
	fgets(new_part,50,stdin);
	
	fprintf(stdout,"Please enter a part number\r\n");
	new_part_id = get_int();

	append_node(new_part,new_part_id);//append to the list
	//HEAD
	fprintf(stdout,"new_part was added\r\n");
}

int print_list(item * head)//print out the parts in the list so far
{
	fprintf(stdout,"\n");
	//HEAD
	
	item *temporary;
	   
	temporary=head;
	   
	if(head==NULL)
	{
		NOLIST
	}
	
	while(temporary->next) 
	{
		fprintf(stdout,"Part:%s\tPartN#:%d\r\n", temporary->part_name,temporary->part_id);
		temporary = temporary->next ;
	}
	
	fprintf(stdout,"Part:%s\tPartN#:%d\r\n", temporary->part_name,temporary->part_id);
	
	options();
}

int make_head_node(char* new_part,int new_part_id)//assign the head value from the first inputed new_part from the user
{
	item *temporary;
	temporary=(item *)malloc(sizeof(item));
	if(temporary==NULL)
	{
		MEMORY_ERROR
	}
	else
	{
		temporary->next  = NULL;
	    strcpy(temporary->part_name,new_part);
		temporary->part_id=new_part_id;
		head = temporary;
	}
}

int create_list()
{
   int list_count,initial_list_number;
   char new_part[50];
   int new_part_id;
   
   head = NULL;
   
   initial_list_number = 0;
   
   fprintf(stdout,"Please enter the number of initial list part_names\r\n");
   initial_list_number = get_int();
   
   fprintf(stdout,"Please enter a part part_name\r\n");
   fgets(new_part,50,stdin);
   
   fprintf(stdout,"Please enter a part number\r\n");
   new_part_id = get_int();
   
   make_head_node(new_part,new_part_id);//this becomes the head
   
   //HEAD
   for(list_count=0;list_count<(initial_list_number-1);list_count++) //allows for ease of initial list creation instead of pressing ber 2 over and over
   {
	  fprintf(stdout,"Please enter a part part_name\r\n");
	  fgets(new_part,50,stdin);
	  
	  fprintf(stdout,"Please enter a part number\r\n");
	  new_part_id = get_int();
	 
	  append_node(new_part,new_part_id);//append everything to the head
   }
   //HEAD
   options();
}

int main() 
{
   options();
   return 0;
}