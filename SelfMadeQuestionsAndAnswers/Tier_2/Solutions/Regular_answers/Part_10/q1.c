/*
	Tier 2 : Part 10	:	Question 1
*/
#include<stdio.h>

int main()
{
	int number_variable = 10;
	int *pointer_to_an_int;
	
	pointer_to_an_int = &number_variable;
	
	printf("the pointer now holds the address %d which contains the number %d\r\n",pointer_to_an_int,*pointer_to_an_int);
	
	return 0;
}