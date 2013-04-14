/*
	Tier 2 : Part 5	:	Question 3
*/
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	char c;
 	int i;
	float f;
	double d;

	//They are all valid casts 
	
	i = c; // legal as int has enough memory to store all of char
	f = i; // legal as float has enough memory to store all of int
	d = f; // legal as double has enough memory to store all of float
	
	return 0;
}