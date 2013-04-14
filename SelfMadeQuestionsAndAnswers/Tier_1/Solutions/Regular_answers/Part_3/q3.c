/*
	Tier 1 : Part 3	:	Question 3
*/
#include<stdio.h>

int main()
{
	int loop_control , loop_count , new_number , sum ;
	
	while(loop_count >= loop_control)
	{
		printf("Please enter an integer\r\n");
		scanf("%d",&new_number);
		sum = sum + new_number;
	}
	
	printf("The sum of the 5 numbers is %d \r\n",sum);
	
	return 0;
}