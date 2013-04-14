/*
	Tier 2 : Part 7	:	Question 4
	
	
*/
#include<stdio.h>


int main()
{
	#ifdef _STDIO_H_
		printf("stdio.h included in this file\r\n");
	#else
		printf("stdio.h not included in this file\r\n");
	#endif
	
	#ifdef _STDLIB_H_
		printf("stdlib.h was included in this file\r\n");
	#else
		printf("stdlib.h not included in this file\r\n");
	#endif
	
	return 0;
}