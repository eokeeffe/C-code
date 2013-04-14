/*
	Tier 2 : Part 2	:	Question 9
	
	for each of the following scopes , list all variable and parameter visible in that scope
	(I).the f function
	(II). the g function
	(III).the block in which e is declared
	(IV).the main function


	Answers:
	(I).  variables visible here are global a, block c
	(II). variables visible here are global a, block d
	(III).variables visible here are global a, block e
	(IV). variables visible here are global a, block f
*/
#include<stdio.h>
int a;
	
void f(int b)
{
	int c;
}

void g(void)
{
	int d;
	{
		int e;
	}
}

int main(void)
{
	int f;
	return 0;
}