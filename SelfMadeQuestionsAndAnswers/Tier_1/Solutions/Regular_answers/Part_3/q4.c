/*
	Tier 1 : Part 3	:	Question 4
	
	The answer included in the comments should indicate that
	the while statement in this case will evaluate both numbers
	to 11 as its only when one hits 11 that it will stop but the incrementing
	is still left in the memory as 1 above the control loop statement
*/
#include<stdio.h>

int main()
{
	int  a = 0 , x = 0;
	
	while(a <= 10 || x <= 10)
	{
		a++;
		printf(" a = %d and x = %d \r\n",a,x);
		++x;
 	}
	
	printf("Final printing , a = %d and x = %d \r\n",a,x);
	
	return 0;
}