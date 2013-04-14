/*
	Tier 1 : Part 8	:	Question 1
	
	The main look here is how parenthesis is crucial to getting 
	accurate results in the program 
	
	In essence ALWAYS USE PARENTHESIS
*/
#include<stdio.h>
#include<stdlib.h>
#define part_1 10
#define	part_2 4+15
#define	part_3 5-2

int main()
{
	int equation_with_no_parenthesis , equation_with_parenthesis ; 
	
	
	
	equation_with_no_parenthesis = part_1 * part_2 / part_3 ;
	
	equation_with_parenthesis = (part_1 * (part_2 / part_3));
	
	printf("%d from the equation\r\n", equation_with_no_parenthesis);
	
	printf("%d from the equation with proper parenthesis\r\n", equation_with_parenthesis);
	
	return 0;
}