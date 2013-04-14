/*
	Tier 2 : Part 4	:	Question 2
	
	Answer:adding values , fairly simple
	
	The conditions for the loop are d is not equal to zero 
	or else add 1 to the function of c + d-1
*/
#include<stdio.h>

int add(int a,int m);

int main()
{
    int a ,b,e;
    b=2;
    a=3;
    e=add(a,b);
	
    printf("The value of addition is %d\n",e);
}
	
int add(int c,int d)
{
    if(d==0)
	{
		return(c);
	}
	else
		{
			return(1+add(c,d-1));
		}
}