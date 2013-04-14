/*
	Tier 1 : Part 8	:	Question 2
	
	The main look here is how parenthesis is crucial to getting 
	accurate results in the program 
	
	In essence ALWAYS USE PARENTHESIS
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int equation_part_1,equation_part_2,equation_part_3,equation_part_4;
	int equation_with_no_parenthesis , equation_with_parenthesis ;
	
	equation_part_1 = 13;
	equation_part_2 = 4;
	equation_part_3 = 5;
	equation_part_4 = 10;
	
	equation_with_no_parenthesis = equation_part_1 * equation_part_2 / equation_part_3 ;
	
	equation_with_parenthesis = (equation_part_1 - ((equation_part_2*equation_part_3)/2) + equation_part_4);
	
	printf("%d from the equation\r\n", equation_with_no_parenthesis);
	
	printf("%d from the equation with proper parenthesis\r\n", equation_with_parenthesis);
	
	return 0;
}