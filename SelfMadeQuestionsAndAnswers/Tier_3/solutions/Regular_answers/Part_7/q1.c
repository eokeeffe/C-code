/*
	Tier 3 : Part 7	:	Question 1
*/
#include<stdio.h>

struct shop_parts
{
	int id_number;
	char part_name[40];
	struct shop_parts *next; // this is how a self referential struct is made 
};							 // now this point can be used to point to a structure 
							 // of type shop_parts and be usable for the linked list

int main()
{
	
	return 0;
}