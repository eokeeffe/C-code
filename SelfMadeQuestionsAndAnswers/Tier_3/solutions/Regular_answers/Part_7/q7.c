/*
	Tier 3 : Part 7	:	Question 7
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
#define HEAD fprintf(stdout,"%s is the head at line %d\r\n",head->part_name,__LINE__);
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
int add_new_part(item * head);//the add new_new_part_idt function that uses the make_node
int options();//options menu for the program
int wait_for_user();//wait for the user to input something before continueing
int print_list(item * head);//print the list out
int end_all(item * head);//de-allocate all the memory if needed and then end the program

//challenge to you , find the mistake with this function , it doesn't delete the last node as  it should
int delete_node();//remove a node from the list and re-point the pointers

int sort_alphabetical();//sort the nodes by alphabetical order
int sort_numerical();//sort the nodes by numerical order
int sort_list();//option list for which sorting function to call

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
	fprintf(stdout,"Please enter a number for the option\r\n");
	fprintf(stdout,"1.create the list\r\n");
	fprintf(stdout,"2.add a part\r\n");
	fprintf(stdout,"3.remove a part\r\n");
	fprintf(stdout,"4.sort the list\r\n");
	fprintf(stdout,"5.print the list\r\n");
	fprintf(stdout,"6.exit\r\n");
	
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
		delete_node();
	}
	if(user_number == 4)
	{
		sort_list();
	}
	if(user_number == 5)
	{
		print_list(head);
	}
	if(user_number == 6)
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

int delete_node()
{	
	item *temporary_pointer_1;
	
	temporary_pointer_1 = head;
	
	int parts_counter = 0, loop_counter=0;
	char remove_part[50];
	
	while(temporary_pointer_1->next!=NULL)//get a count of all elements
	{
		temporary_pointer_1=temporary_pointer_1->next;
		parts_counter++;
	}
	item *array[parts_counter+1];//create an array of pointers, better than having to assign troublesome variables for each case,after its done it will be de-allocated 
					 //when the function terminates
	printf("Please enter the name of the part to delete\r\n");
	fgets(remove_part,50,stdin);
	
	if(temporary_pointer_1==NULL)
	{
		NOLIST 
		options();
	}
	else
	{
		temporary_pointer_1=head;
		if(strcmp(head-> part_name,remove_part)==0)
		{
			if(head->next!=NULL)
			{
				head=head->next;
			}
			HEAD
		}//check if the head is to be changed and change it 
		
		temporary_pointer_1=head;//reset the head
		
		while(temporary_pointer_1->next!=NULL)
		{
			if(temporary_pointer_1->next!=NULL)
			{
				array[loop_counter]=temporary_pointer_1;//pass all pointers into the array , this way the next in line and previous are stored
				temporary_pointer_1=temporary_pointer_1->next;
				loop_counter++;
			}
		}
		temporary_pointer_1 = head;//reset the temporary_pointer_1 pointer back to the head
		loop_counter = 0;
		while(temporary_pointer_1->next!=NULL)
		{
			if(strcmp(temporary_pointer_1->part_name,remove_part) == 0)//get the element that is being searched for
			{
				if(temporary_pointer_1->next == NULL)
				{
					free(temporary_pointer_1);
					temporary_pointer_1=NULL;
				}//if the element is the last than null it
				else	
				{
					array[loop_counter-1]->next=array[loop_counter+1];//the pointer from the prevoius now points to the one after the de-allocate space
					free(temporary_pointer_1);
				}
			}
			if(temporary_pointer_1->next!=NULL)
			{
				temporary_pointer_1 = temporary_pointer_1->next;
				loop_counter++;
			}
		}
	}
	options();
	return 0;
}

int sort_list()
{
	int user_choice;
	fprintf(stdout,"Please enter a number for the sorting method\r\n");
	fprintf(stdout,"1.Sort Alphabetically\r\n");
	fprintf(stdout,"2.Sort Numerically\r\n");
	user_choice = get_int();
	
	switch(user_choice)
	{
		case 1:
		{
			sort_alphabetical();
			break;
		}
		case 2:
		{
			sort_numerical();
			break;
		}
		default:
		{
			options();
			return 0;
			break;
		}
	}
	
	return 0;
}

int sort_alphabetical()
{
	item *temporary_pointer_1,*temporary_pointer_2,*temporary_pointer_3;
	
	temporary_pointer_1 = head;
	
	int node_count = 0 , head_count = 0 , swap_part_name , swap_part_number;
	
	if(temporary_pointer_1 == NULL)
	{
		NOLIST
	}
	else
	{
		while(temporary_pointer_1->next)//count the number of elements in the list for the sorting
		{
			node_count++;
			temporary_pointer_1 = temporary_pointer_1->next;
		}
		temporary_pointer_1=head;//reset the head
		
		while(head_count <= node_count)//sort the elements by the number of ones in the list, the head is reset each time to make sure all elements are sorted
		{
			if(temporary_pointer_1->part_name[0] > temporary_pointer_1->next->part_name[0])
			{
				//HEAD
				//LINE
				temporary_pointer_2=(item *)malloc(sizeof(item));
				if(temporary_pointer_2==NULL)
				{
					MEMORY_ERROR
					break;
				}
				else
				{
					strcpy(temporary_pointer_2->part_name,temporary_pointer_1->part_name);// I know bubble sort can be slow but its useful in this situation
					strcpy(temporary_pointer_1->part_name,temporary_pointer_1->next->part_name);
					strcpy(temporary_pointer_1->next->part_name,temporary_pointer_2->part_name);
					
					swap_part_name=temporary_pointer_1->part_id;//swap part numbers to correspnoding name
					temporary_pointer_1->part_id = temporary_pointer_1->next->part_id;
					temporary_pointer_1->next->part_id = swap_part_name;
					
					//LINE
					
				}
			}
			temporary_pointer_1 = temporary_pointer_1->next;
			if(temporary_pointer_1->next==NULL)
			{
				head_count++;
				temporary_pointer_1=head;
			}//cover all elements of the list by reseting the head (a) times
		}
		
		temporary_pointer_3=head;//set the head value
		if(temporary_pointer_3->part_name[0] > temporary_pointer_3->next->part_name[0])//get the first element and check that its the lowest ranked and set head
		{
				temporary_pointer_2=(item *)malloc(sizeof(item));
				
				if(temporary_pointer_2==NULL)
				{
					MEMORY_ERROR
				}
				else
				{
					strcpy(temporary_pointer_2->part_name,temporary_pointer_3->part_name);
					strcpy(temporary_pointer_3->part_name,temporary_pointer_3->next->part_name);
					strcpy(temporary_pointer_3->next->part_name,temporary_pointer_2->part_name);
					//LINE
					
				}
		}
		//HEAD
	}
	options();
	return 0;
}

int sort_numerical()
{
	item *temporary_pointer_1,*temporary_pointer_2,*temporary_pointer_3;
	
	temporary_pointer_1 = head;
	
	int node_count = 0 , head_count = 0 , swap_part_name , swap_part_number;
	
	if(temporary_pointer_1 == NULL)
	{
		NOLIST
	}
	else
	{
		while(temporary_pointer_1->next)//count the number of elements in the list for the sorting
		{
			node_count++;
			temporary_pointer_1 = temporary_pointer_1->next;
		}
		temporary_pointer_1=head;//reset the head
		
		while(head_count <= node_count)//sort the elements by the number of ones in the list, the head is reset each time to make sure all elements are sorted
		{
			if(temporary_pointer_1->part_id > temporary_pointer_1->next->part_id)
			{
				//HEAD
				//LINE
				temporary_pointer_2=(item *)malloc(sizeof(item));
				if(temporary_pointer_2==NULL)
				{
					MEMORY_ERROR
					break;
				}
				else
				{
					strcpy(temporary_pointer_2->part_name,temporary_pointer_1->part_name);// I know bubble sort can be slow but its useful in this situation
					strcpy(temporary_pointer_1->part_name,temporary_pointer_1->next->part_name);
					strcpy(temporary_pointer_1->next->part_name,temporary_pointer_2->part_name);
					
					swap_part_name=temporary_pointer_1->part_id;//swap part numbers to correspnoding name
					temporary_pointer_1->part_id = temporary_pointer_1->next->part_id;
					temporary_pointer_1->next->part_id = swap_part_name;
					
					//LINE
					
				}
			}
			temporary_pointer_1 = temporary_pointer_1->next;
			if(temporary_pointer_1->next==NULL)
			{
				head_count++;
				temporary_pointer_1=head;
			}//cover all elements of the list by reseting the head (a) times
		}
		
		temporary_pointer_3=head;//set the head value
		if(temporary_pointer_3->part_name[0] > temporary_pointer_3->next->part_name[0])//get the first element and check that its the lowest ranked and set head
		{
				temporary_pointer_2=(item *)malloc(sizeof(item));
				
				if(temporary_pointer_2==NULL)
				{
					MEMORY_ERROR
				}
				else
				{
					strcpy(temporary_pointer_2->part_name,temporary_pointer_3->part_name);
					strcpy(temporary_pointer_3->part_name,temporary_pointer_3->next->part_name);
					strcpy(temporary_pointer_3->next->part_name,temporary_pointer_2->part_name);
					//LINE
					
				}
		}
		//HEAD
	}
	options();
	return 0;
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