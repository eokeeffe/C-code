/*
	Tier 1 : Part 3	:	Question 9
	
	The comments should indicate that the scanf function has crashed 
	due to the character being entered 
	
	If the answer includes anything to do with the I/O buffer being contaminated 
	then the answerer is aware of the danger of scanf
*/
#include<stdio.h>

int main()
{
	int x = 0 , user_input = 0 , control_statement = 10;
	
	while( x < control_statement)
	{
		printf("User input = %d \r\n",user_input);
		scanf("%d",&user_input);
		x++;
	}
	
	printf("Crashed didn't it \r\n");
	
	return 0;
}