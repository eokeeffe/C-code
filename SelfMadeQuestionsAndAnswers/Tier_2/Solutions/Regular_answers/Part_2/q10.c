/*
	Tier 2 : Part 2	:	Question 10
	
	for each of the following scopes , list all variable and parameter visible in that scope
    (I).the f function
	(II). the g function
	(III).the block in which e is declared
	(IV).the main function
	
	Answers:
	(I).  variables visible here are block variable b and d, global c
	(II). variables visible here are parameter a, block c
	(III).variables visible here are block a and d  global b and c
	(IV). variables visible here are block c and d ,global b
*/
#include<stdio.h>

int b,c;
	
void f(void)
{
	int b,d;
}

void g(int a)
{
	int c;
	{
		int a,d;
	}
}

int main(void)
{
	int c,d;
	return 0;
}

