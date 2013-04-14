/*
	Tier 1 : Part 3	:	Question 9
	
	The scanf function in this case must be equal to the number of inputs it is taking
	in this case its only taking one input so it has to be equal to 1 or else it has 
	failed
*/
#include<stdio.h>

int main()
{
	int x = 0 , user_input = 0 , control_statement = 10;
	
	printf("please enter a number \r\n");
	
	while( scanf("%d",&user_input) == 1 && x < control_statement)
	{
		printf("User input = %d \r\n",user_input);
		x++;
	}
	
	printf("Handy way of dealing with the scanf in a loop \r\n");
	printf("trust me this will save time in the future with C \r\n");
	
	return 0;
}