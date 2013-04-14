/*
	Tier 2 : Part 5	:	Question 4
	
	Same as the last section
	
	Although depending on the amount of information in each of the identifiers 
	the data-type may not be able to hold onto all information 
	Therefore some of these could produce an incorrect result
*/
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	char c;
	short int s;	
	int i;
	unsigned int u;
	long int l;
	unsigned long int ul;
	float f;
	double d;
	long double ld;

	i = i + c;
	i = i + s;
	u = u + i;
	l = l + u;
	ul = ul + l;
	f = f + ul;
	d = d + f;	
	ld = ld + d;
	
	
	return 0;
}