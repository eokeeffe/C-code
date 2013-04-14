/*
	Tier 3 : Part 3	:	Question 5
	
	Since the union holds only the memory type of the largest member , the numbers other than that
	member will be held in the union . For instance the the 2 assigned to a is okay but if the number 
	was big enough to exceed the maximum value of a double but not an int , then the value will be 
	erronous at printing time . This is one of the problems with unions
	
	Not only that but the numbers will only be correcct for the 
	last number to be assigned to the union , this is shown below when the 
	a is given the value 2 then b the value 8.987
	but when printed the a will give a weird answer and b will give the correct and one 
	and vice versa when the order of assignement is reversed and only a is printed correctly
*/
#include<stdio.h>

union testing_numbers
{
	int a;
	double b;
	
}var;

int main ()
{
	var.a = 2;
	var.b = 8.9876;
	
	printf("a = %d \r\n",var.a);
	printf("b = %lf \r\n",var.b);
	
	var.b = 8.9876;
	var.a = 2;
	
	printf("a = %d \r\n",var.a);
	printf("b = %lf \r\n",var.b);
	
	
	return 0;
}