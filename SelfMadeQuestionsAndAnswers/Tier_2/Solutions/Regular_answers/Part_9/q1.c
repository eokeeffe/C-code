/*
	Tier 2 : Part 9	:	Question 1
		
	In computer science we always refer to the first as 0
	if you want a nice way of remembering this just think that 
	computers only deal with 0 and 1's , so it will start from 0 always
*/
#include<stdio.h>

int main()
{
	int A[4]={1,2,3,4};
	int loop_count=0;
	
	while(loop_count<4)
	{
		printf("A[%d]=%d\r\n",loop_count,A[loop_count]);
		loop_count++;
	}
	
	return 0;
}