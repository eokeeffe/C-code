/*
	Tier 3 : Part 4	:	Question 1
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<assert.h>

int main ()
{
	int A,B;
	int maximum_int = 2147483647;
	
	
	printf("Please an integer number to get the square root of \r\n");
	scanf("%d%*c",&A);
	
	B = sqrt(A);
	
	if( errno != 0 )
	{
		printf("%s Caused by negative square root or number above %d\r\n",strerror(errno),maximum_int);	
		return 0;
	}
	else
	{
		printf("No error here\r\n");
		printf("%d is the answer\r\n",B);
		return 0;
	}
}