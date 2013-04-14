/*
	Tier 2 : Part 6	:	Question 4
*/
#include<stdio.h>

#define PRINT_LINE_NUMBER printf("%d is the line number\r\n",__LINE__);
//make sure to note that each of the defined standard macros use two _ , like __
// __LINE__ is a macro itself , its defined in stdio

int main()
{

	PRINT_LINE_NUMBER
	
	return 0;	
}