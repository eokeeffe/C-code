/*
	Tier 1 : Part 8	:	Question 10
	
	As you may have become more aware of precedence because of this section you'll
	know that is the cast operator then the sizeof operator 
	then the parenthesis which will be done seperetaly 
	then the logical operators 
	then the remainder operator 
	then of course the assignement operator
	
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a,b,c,d;
	float answer;
	
	(float) sizeof(a/b+c*d) +a && b || c % d ; // is the original equation

	answer = (float) sizeof(a/(b+c*d)) +((a && b) || c) % d; // the fixed equation which equals 5.000
	
	printf("%f is the answer\r\n",answer);
	return 0;
}