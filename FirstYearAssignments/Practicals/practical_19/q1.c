/*Evan O'Keeffe
  10324289
  practical 19 question1
*/
#include<stdio.h>
#include<stdlib.h>

struct data
{
	struct data *next;
};//self referential data structure


int main()
{	
	struct data *p,*first;
	for (p = first; p != NULL; p = p->next)
	{
		first = p->next;
		free (p);
	}
	return 0;
}//the problem that arose from the initial code was 
 //that when the first pointer was freed from memory
 //that the linked pointers after that were lost as the first pointer
 // had the location to the next , as such it would only free the first
 //pointer but not the preceeding ones