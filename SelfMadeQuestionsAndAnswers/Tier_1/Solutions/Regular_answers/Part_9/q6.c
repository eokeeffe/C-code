/*
	Tier 1 : Part 9	:	Question 6
	
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int draw_times_table();

int main()
{
	draw_times_table();
	return 0;
}

int draw_times_table()
{
	int vertical_count,horizontal_count;
	int control_statement=10 , multiplier, one=1;
	
	for(vertical_count=0;vertical_count<control_statement;vertical_count++)
	{
		multiplier = vertical_count;
		for(horizontal_count=0;horizontal_count<control_statement;horizontal_count++)
		{
			if(multiplier==1)
			{
				printf(" %d ",multiplier*one); 
			}
			if(multiplier*horizontal_count >= 10)
			{
				printf(" %d ",multiplier*horizontal_count); 
			}
			if(multiplier!=1&&multiplier!=10)
			{
				printf(" %d ",multiplier*horizontal_count);
			}
		}
		printf("\r\n");
	}
	
	return 0;
}