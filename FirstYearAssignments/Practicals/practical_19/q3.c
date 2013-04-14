/*Evan O'Keeffe
  10324289
  practical19 question 3
  
  comements below
*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//macro's for various debugging routines
#define EXIST printf("part already exists , returning to options menu\r\n");
#define NEXIST printf("part doesn't exist , returning to options menu\r\n");
#define MERROR printf("Memory allocation failed\r\n");
#define DERROR printf("Memory de-allocation failed at %d in %s\r\n",__LINE__,__FILE__);
#define LINE printf("%d in %s\r\n",__LINE__,__FILE__);
#define NOLIST printf("No list has been located\r\n");
#define HEAD printf("%s is the head at line %d\r\n",head->name,__LINE__);
//self referential structure that is used for this singly linked list
struct data 
{
   char name[50];
   int part;//part number
   int hand;//number of parts on hand
   struct data *next;
};
typedef struct data item;
item *head;//head of the linked list

void search();//search for an id number
void change();//change a quantity 
void create_list();//create a list
void append_node(char* city,int par,int num);//append a part to the number
void sortl();//sort the list
void mnode(char* city,int par,int num);//create a new node in the list
void add_part(item * head);//the add city function that uses the mnode
void options();//options menu for the program
void wait_for_user();//wait for the user to input something before continueing
void print_list(item * head);//print the list out
void end_all(item * head);//de-allocate all the memory if needed and then end the program
void delete_node();//remove a node from the list and restructure the pointers, works for nearly all cases but crashes when either the bottom or second last
				   //node are choosen

void options()
{
	int user;
	user=0;
	printf("\n\n\n");
	printf("Please enter a number for the option\r\n");
	printf("1.create the list\r\n");
	printf("2.add a part\r\n");
	printf("3.change the quantity of a part\r\n");
	printf("4.search for a part\r\n");
	printf("5.delete a part\r\n");
	printf("6.sort list(part name)\r\n");
	printf("7.print the list\r\n");
	printf("8.exit\r\n");
	scanf("%d%*c",&user);
	if(user==1){create_list();}
	if(user==2){add_part(head);}
	if(user==3){change();}
	if(user==4){search();}
	if(user==5){delete_node();}
	if(user==6){sortl();}
	if(user==7){print_list(head);}
	if(user==8){end_all(head);}
	else
	{printf("Please enter a valid option\r\n");options();}
}

void search()
{
	item *temp;
	temp=head;
	int look,i=0;
	if(head==NULL){NOLIST wait_for_user(); options();}
	else
	printf("Please enter the part ID to look for\r\n");
	scanf("%d",&look);
	while(temp->next!=NULL)
	{
		if(temp->part==look){printf("Part:%s\tPartN#:%d\tNumber on hand:%d\n", temp->name,temp->part,temp->hand);i++;}
		if(temp->next!=NULL){temp=temp->next;}
	}
	if(i==0){NEXIST wait_for_user();options();}
	else
		{
			
			wait_for_user();
			options();
		}
	
    
}

void change()
{
	item *temp;
	temp=head;
	int new,id,i=0;
	if(head==NULL){NOLIST wait_for_user(); options();}
	else
	printf("please enter the id number of the part to change\r\n");
	scanf("%d",&id);
	printf("please enter the new quatitiy of that part \r\n");
	scanf("%d",&new);
	while(temp->next!=NULL)
	{
		if(temp->part==id)
		{
			temp->hand=new;
			i++;
			break;
		}
		if(temp->next!=NULL){temp=temp->next;}
	}
	if(i==0)
	{
		NEXIST
		wait_for_user();
		options();
	}
	else
		printf("Part quantity changed\r\n");
		wait_for_user();
		options();
	
}

void wait_for_user()
{
	char dummy[50];
	printf("enter something then enter\r\n");
	scanf("%s",&dummy);
}

void delete_node()
{	
	fflush(stdin);
	item *temp,*prev,*temp1;
	temp=head;
	int i=0,k=0;
	char rem[50];
	while(temp->next!=NULL)//get a count of all elements
	{
		temp=temp->next;
		i++;
	}
	item *array[i+1];//create an array of pointers, better than having to assign troublesome variables for each case,after its done it will be de-allocated 
					 //when the function terminates
	printf("Please enter the name of the part to delete\r\n");
	scanf("%s",&rem);
	if(temp==NULL){NOLIST options();}
	else
	{
		temp=head;
		if(strcmp(head->name,rem)==0){if(head->next!=NULL){head=head->next;}HEAD}//check if the head is to be changed and change it 
		temp=head;//reset the head
		
		while(temp->next!=NULL)
		{
			if(temp->next!=NULL)
			{
				array[k]=temp;//pass all pointers into the array , this way the next in line and previous are stored
				temp=temp->next;
				k++;
			}
		}
		temp=head;//reset the temp pointer back to the head
		k=0;
		while(temp->next!=NULL)
		{
			if(strcmp(temp->name,rem)==0)//get the element that is being searched for
			{
				if(temp->next==NULL){free(temp);temp=NULL;}//if the element is the last than null it
				else	
					
					array[k-1]->next=array[k+1];//the pointer from the prevoius now points to the one after the de-allocate space
					free(temp);
			}
			if(temp->next!=NULL)
			{
				temp=temp->next;
				k++;
			}
		}
		
			
		
	}
	options();
}

void sortl()
{
	item *temp,*temp1,*temp2,*temp3;
	temp=head;
	int i=0,a=0,b=0,pat,nut;
	if(temp==NULL){NOLIST}
	else
	{
		while(temp->next)//count the number of elements in the list for the sorting
		{
			i++;
			temp=temp->next;
		}
		temp=head;//reset the head
		b=i;
		while(a<=b)//sort the elements by the number of ones in the list, the head is reset each time to make sure all elements are sorted
		{
			if(temp->name[0]>temp->next->name[0])
			{
				//HEAD
				//LINE
				temp2=(item *)malloc(sizeof(item));
				if(temp2==NULL){MERROR break;}
				else
				{
					strcpy(temp2->name,temp->name);// I know bubble sort can be slow but its useful in this situation
					strcpy(temp->name,temp->next->name);
					strcpy(temp->next->name,temp2->name);
					
					pat=temp->part;//swap part numbers to correspnoding name
					temp->part=temp->next->part;
					temp->next->part=pat;
					
					nut=temp->hand;//swap the number of the parts to the corresponding name
					temp->hand=temp->next->hand;
					temp->next->hand=nut;
					
					//LINE
					
				}
			}
			temp=temp->next;
			if(temp->next==NULL){a++;temp=head;}//cover all elements of the list by reseting the head (a) times
		}
		
		temp3=head;//set the head value
		if(temp3->name[0] > temp3->next->name[0])//get the first element and check that its the lowest ranked and set head
		{
				temp2=(item *)malloc(sizeof(item));
				if(temp2==NULL){MERROR}
				else
				{
					strcpy(temp2->name,temp3->name);
					strcpy(temp3->name,temp3->next->name);
					strcpy(temp3->next->name,temp2->name);
					//LINE
					
				}
		}
		//HEAD
	}
	
	options();
}

void end_all(item * head)
{
   item *temp;
   temp=head;
   if(head==NULL){printf("Thank you for using linked list V1.0\r\n");exit(0);}
   while(temp->next) 
   {
      temp = temp->next ;//take all elements except the head and de-allocate first or the pointers to the will be lost
	  free(temp);
   }
   free(head);//after they are finished free the head to de-allocate the last part of the list
   printf("Thank you for using linked list V1.0\r\n");
   exit(0);
}

void append_node(char* city,int par,int num)
{
	//HEAD
	item *temp;
	temp=head;
	if(temp==NULL){NOLIST}
	else
	{
		while(temp->next)
		{
			if(strcmp(temp->name,city)==0){EXIST wait_for_user(); options();}
			if(temp->part==par){EXIST wait_for_user(); options();}
			else 
				temp=temp->next;
		}
		temp->next=(item *)malloc(sizeof(item));//take the null element and append the new city
		strcpy(temp->next->name,city);
		temp->next->part=par;
		temp->next->hand=num;
		temp->next->next=NULL;//make the tail null again
	}
	//HEAD
}

void add_part(item * head)
{
	char city[50];
	int par,num;
	printf("Please enter a new city\r\n");
	scanf("%s",&city);
	printf("Please enter a part number\r\n");
	scanf("%d%*c",&par);
	printf("Please enter number of parts on hand\r\n");
	scanf("%d%*c",&num);
	append_node(city,par,num);//append to the list
	//HEAD
	printf("city was added\r\n");
}

void print_list(item * head)//print out the parts in the list so far
{
   printf("\n");
   //HEAD
   item *temp;
   temp=head;
   if(head==NULL){NOLIST}
   while(temp->next) 
   {
      printf("Part:%s\tPartN#:%d\tNumber on hand:%d\n", temp->name,temp->part,temp->hand);
      temp = temp->next ;
   }
   printf("Part:%s\tPartN#:%d\tNumber on hand:%d\n", temp->name,temp->part,temp->hand);
   options();
}

void mnode(char* city,int par,int num)//assign the head value from the first inputed city from the user
{
	item *temp;
	temp=(item *)malloc(sizeof(item));
	if(temp==NULL){MERROR}
	else
	{
		temp->next  = NULL;
	    strcpy(temp->name,city);
		temp->part=par;
		temp->hand=num;
		head = temp;
	}
}

void create_list()
{
   int i,a;
   char city[50];
   int par,num;
   head = NULL;
   a=0;
   printf("Please enter the number of initial list names\r\n");
   scanf("%d",&a);
   printf("Please enter a part name\r\n");
   scanf("%s",&city);
   printf("Please enter a part number\r\n");
   scanf("%d%*c",&par);
   printf("Please enter the number of parts on hand\r\n");
   scanf("%d%*c",&num);
   mnode(city,par,num);//this becomes the head
   //HEAD
   for(i=0;i<(a-1);i++) //allows for ease of initial list creation instead of pressing number 2 over and over
   {
	  printf("Please enter a part name\r\n");
	  scanf("%s",&city);
	  printf("Please enter a part number\r\n");
	  scanf("%d%*c",&par);
	  printf("Please enter the number of parts on hand\r\n");
	  scanf("%d%*c",&num);
	  append_node(city,par,num);//append everything to the head
   }
   //HEAD
   options();
}

int main() 
{
   options();
   return 0;
}