/*
	Tier 2 : Part 2	:	Question 6
	
	The count in the main is of function scope , it may have the same identifier and 
	type as the global but this one is a local variable that will only last as long as
	the function is running. this is the block variable
	
	The other count before the main is the Global variable as the other function
	is able to access it and print the value of it , which hasn't been changed
	by the incrementing of the count in the main
*/
#include<stdio.h>

int other_function();

int count=5;

int main()
{
	int count=0,control_statement=100;
	
	while(count < control_statement)
	{
		count++;
	}
	
	printf(" count = %d and count = %d \r\n",count,count);
	
	other_function();
	return 0;
}

int other_function()
{
	printf("yet the real count really = %d\r\n",count);
	return 0;
}

