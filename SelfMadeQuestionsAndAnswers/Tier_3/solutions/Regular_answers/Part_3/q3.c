/*
	Tier 3 : Part 3	:	Question 3
	
	The reasons this happens is the compiler will automatically assign a value to 
	the enum members at compile time if they haven't already been assigned a number 
	previously
	And as always the first number will of course start from zero and continue until the 
	number assigned is changed in which case it will increment from that point 
	
	For example the member d=6 , e=7, f=8 , g=20 , h=21 as shown when running this program
*/
#include<stdio.h>

enum numbers
{
	a,
	b,
	c,
	d = 6,
	e,
	f,
	g = 20,
	h
};


int main ()
{
	enum numbers variable;
	
	printf("The numbers in the enum are\r\n");
	
	variable = a;	// the way to access the members of an enum are simply to equate them 
					// enum variable to another variable of the same type
					 
	printf("a = %d \r\n",variable);
	
	variable = b;
	printf("b = %d \r\n",variable);
	
	variable = c;
	printf("c = %d \r\n",variable);
	
	variable = d;
	printf("d = %d \r\n",variable);
	
	variable = e;
	printf("e = %d \r\n",variable);
	
	variable = f;
	printf("f = %d \r\n",variable);
	
	variable = g;
	printf("g = %d \r\n",variable);
	
	variable = h;
	printf("h = %d \r\n",variable);
	
	return 0;
}