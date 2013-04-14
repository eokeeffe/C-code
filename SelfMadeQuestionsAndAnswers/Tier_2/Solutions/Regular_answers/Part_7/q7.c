/*
	Tier 2 : Part 7	:	Question 7
	
*/
#include<stdio.h>
#define swap(a,b)	{ 				\
						a ^= b; 	\
									\
						b ^= a; 	\
									\
						a ^= b; 	\
					}

int main()
{
	int a=2,b=5;
	printf("before INT_SWAP a= %d and b=%d\r\n",a,b);
	
	swap(a,b);
	
	printf("after INT_SWAP a= %d and b=%d\r\n",a,b);
	
	return 0;
}