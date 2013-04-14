/*
	Tier 2 : Part 7	:	Question 9
	
*/
#include<stdio.h>
#include<string.h>

#define ERROR(identifier,token) fprintf(stderr,"FILE:%s  LINE:%d Identifier:%s = "token"\r\n"	\
										,__FILE__,__LINE__,#identifier,identifier);

int main()
{
	char bad_string[10];
	strcpy(bad_string,"This was a bad string");
	
	ERROR(bad_string,"%s")
	
	return 0;
}