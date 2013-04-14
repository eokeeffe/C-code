/*
	Tier 3 : Part 3	:	Question 9
	
	So this allows the user to enter whatever they like into the array
	without the loop crashing from the scanf , this is one way 
	of taking input for anythig but does however use some large amounts of
	memory in doing so as the union will always be as big as the largest data type
	
	which in this case is the double which takes 64 bits at least per array member
*/
#include<stdio.h>

union input
{
	char character;
	int number;
	float floating_number;
	double double_precision_number;
}array[12];

int main ()
{
	int loop_counter=0;
	
	printf("Please enter anything here\r\n");
	
	while(loop_counter<12)
	{
		scanf("%c",&array[loop_counter]);
		loop_counter++;
	}
	
	loop_counter=0;
	
	while(loop_counter<12)
	{
		printf("%c %d %f %lf \r\n",array[loop_counter].character,	
								   array[loop_counter],
								   array[loop_counter],
								   array[loop_counter]);
		loop_counter++;
	}
	
	return 0;
}