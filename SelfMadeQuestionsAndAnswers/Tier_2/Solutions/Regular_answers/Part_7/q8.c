/*
	Tier 2 : Part 7	:	Question 8
	
*/
#include<stdio.h>

int main()
{
	#ifdef __unix
		fprintf(stderr,"%s is the current system\r\n","Unix");
	#elif defined _WIN32 // _WIN32 is defined by most compilers available for the Windows operating system (but not by all).
		fprintf(stderr,"%s is the current system\r\n","Windows");
	#endif
	
	return 0;
}