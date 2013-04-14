/*
	Tier 1 : Part 8	:	Question 9
	
	answer : No , why , correct with ( p == 0 ) ? ( p += 1 ) : ( p += 2 )
	otherwise it defaults as ( p == 0 ? p += 1 : p ) += 2
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int p;
	
	p=0;
	//p == 0 ? p += 1: p += 2 ; //techincally wont compile on most machines too from the error 
								//lvalue required left of assignement
	printf("p=%d\r\n",p);
	
	p=0;
	( p==0 ) ? ( p += 1 ):( p += 2 );
	
	printf("p = %d\r\n",p);
	
	return 0;
}