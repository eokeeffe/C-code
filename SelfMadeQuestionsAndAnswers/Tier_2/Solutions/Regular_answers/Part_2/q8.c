/*
	Tier 2 : Part 2	:	Question 8
	
	since the i variable is global the first time its called in 
	print line , the value will be incremented to 10
	so when the other function calls the value to increment 
	in the for loop 

	the for loop checks the condition and 
	forgoes printing anything out as the condition i <=10 is already true
*/
#include<stdio.h>

int i;
void print_line(void)
{
	for(i=1;i<=10;i++)
	{
		printf("*");
	}
}

 void print_all_rows(void)
{
	for(i=1;i<=10;i++)
	{
		print_line();
		printf("\n");
	}
}

int main()
{
	print_line();
	print_all_rows();
	return 0;
}