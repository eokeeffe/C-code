/*
	Tier 1 : Part 3	:	Question 6
*/
#include<stdio.h>

int main()
{
	int  horizontal_counting = 0 , vertical_counting = 0;
	
	for(horizontal_counting = 0,vertical_counting = 0 ; horizontal_counting < 10 ; horizontal_counting++)
	{
		for(vertical_counting = 0 ; vertical_counting < 10 ; vertical_counting++)
		{
			printf("*");
		}
		
		printf("\r\n");
	}
	
	return 0;
}