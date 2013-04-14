/*
	Tier 3 : Part 7	:	Question 2
*/
#include<stdio.h>

typedef struct shop_parts
{
	int id_number;
	char part_name[40];
};

typedef struct shop_parts *next; // this is how a self referential struct is made with the typedef
								 // the difference is that the compiler wont know the 
								 // data type shop_parts as it hasn't been created yet
								 // it this was directly declared in the struct

int main()
{
	
	return 0;
}