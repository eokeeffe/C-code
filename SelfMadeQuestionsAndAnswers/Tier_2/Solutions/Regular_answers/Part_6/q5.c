/*
	Tier 2 : Part 6	:	Question 5
*/
#include<stdio.h>

#define PRINT_FUNCTION_NAME printf("%s is the function name\r\n",__func__);
// __func__ is a macro itself , its defined in stdio

int main()
{

	PRINT_FUNCTION_NAME
	
	return 0;	
}