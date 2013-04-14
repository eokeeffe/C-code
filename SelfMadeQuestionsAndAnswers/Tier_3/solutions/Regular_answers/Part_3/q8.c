/*
	Tier 3 : Part 3	:	Question 8
*/
#include<stdio.h>

union input
{
	char character;
	int number;
	float floating_number;
	double double_precision_number;
}variable;

int main ()
{
	printf("Please enter anything here\r\n");
	scanf("%c",&variable);
	
	printf("%d %c %f %lf \r\n",variable.number,	
							   variable.character,
							   variable.floating_number,
							   variable.double_precision_number);
	
	return 0;
}