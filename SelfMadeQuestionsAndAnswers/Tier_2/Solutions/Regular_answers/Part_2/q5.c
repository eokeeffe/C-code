/*
	Tier 2 : Part 2	:	Question 5
	
	it legal in this case as the global variable isn't touched
	What happens is the varaible int i=2 in function f()
	is a block variable , i.e its only visible to the function and its 
	the functions own variable , once the function ends the value in 
	i will be gone and the other global i will be used instead 
	
	J will take the value in the global i since the other i is declared
	after it is assigned the value
	
*/
#include<stdio.h>

int i=1;

void f(void)
{
	int j=i;
	int i=2;
	
	printf("j=%d and i=%d \r\n",j,i);
}

int main()
{

	f();
	printf("i=%d \r\n",i);
	return 0;
}
