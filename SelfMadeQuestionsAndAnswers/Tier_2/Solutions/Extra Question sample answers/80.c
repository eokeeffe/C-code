/*
	Tier 2 : Extra_Questions	:	Question 80
	
	This question was looking for the identifier that caused the problem
	This is a simple little macro that can become very handy for bigger 
	programs
*/
#include<stdio.h>
#define dumpme(x,fmt) printf("%s:%u: %s="fmt,__FILE__,__LINE__,#x,x)

int main()
{
	int foo;
	
	dumpme(foo,"%d");
	
	return 0;
}