/*
	Tier 2 : Part 6	:	Question 6
*/
#include<stdio.h>

#define PRINT_DATE_AND_TIME_COMPILED printf("%s %s is the date and time this \
											 program was Compiled\r\n",__DATE__,__TIME__);
// __DATE__ and __TIME__ are other macros defined in stdio
// make sure not to try and use them to tell current time 
// they will only work at compile time and that will stick with the program

int main()
{

	PRINT_DATE_AND_TIME_COMPILED
	
	return 0;	
}