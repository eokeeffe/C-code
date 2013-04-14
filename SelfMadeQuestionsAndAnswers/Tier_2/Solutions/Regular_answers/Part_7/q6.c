/*
	Tier 2 : Part 7	:	Question 6
	
	Information on compiler and operating system directives is
	refered from http://www.kohala.com/start/systype.h.sun.txt
	
*/
#include<stdio.h>
#include<string.h>
#ifdef __unix
		#include<unistd.h>
#elif defined _WIN32 // _WIN32 is defined by most compilers available for the Windows operating system (but not by all).
		#include<windows.h>
#endif


int main()
{
	#ifdef __unix
		printf("Unix header file included\r\n");
	#elif defined _WIN32 // _WIN32 is defined by most compilers available for the Windows operating system (but not by all).
		printf("Windows header file included\r\n");
	#endif
	return 0;
}