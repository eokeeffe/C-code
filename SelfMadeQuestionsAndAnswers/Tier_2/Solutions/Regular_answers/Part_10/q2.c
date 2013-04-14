/*
	Tier 2 : Part 10	:	Question 2
*/
#include<stdio.h>

int *half_the_int(int *pointer_to_a_int);

int main()
{
	int number_variable = 1234;
	int *pointer_to_a_int;
	
	pointer_to_a_int = &number_variable;
	
	printf("the pointer now holds the address %d which contains the number %d\r\n",pointer_to_a_int,*pointer_to_a_int);
	
	half_the_int(pointer_to_a_int);
	
	printf("the pointer still holds the address %d which contains the number %d now\r\n",pointer_to_a_int,*pointer_to_a_int);
	
	return 0;
}

int *half_the_int(int *pointer_to_a_int)
{	
	*pointer_to_a_int = *pointer_to_a_int / 2;
	
	return pointer_to_a_int;
}