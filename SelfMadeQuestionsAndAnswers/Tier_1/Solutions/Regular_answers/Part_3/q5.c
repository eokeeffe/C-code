/*
	Tier 1 : Part 3	:	Question 5
*/
#include<stdio.h>

int main()
{
	int  horizontal_counting = 0 , vertical_counting = 0;
	
	while(horizontal_counting < 10 )
	{
		vertical_counting = 0 ; //resets the vertical counting variable
		
		while(vertical_counting < 10 )
		{
			printf("*");
			vertical_counting++;
		}
		
		horizontal_counting++;
		
		printf("\r\n");
	}
	
	return 0;
}