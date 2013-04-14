/*
	Tier 2 : Part 7	:	Question 2
*/
#include<stdio.h>
#include<string.h>


int main()
{
	char change[100];
	
	#ifdef NULL
		strcpy(change,"Compiler");
	#else
		#define NULL 0
		strcpy(change,"User");
	#endif

	printf("NULL is defined as %d and by the %s\r\n",NULL,change);
	return 0;
}