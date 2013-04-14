/*
	Tier 1 : Part 7	:	Question 4
	
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=5,b=10,c=0,z;
	
	printf("what is the out come of z= (a<b)? b :c\r\n");
	printf("if a=%d , b=%d , c=%d \r\n",a,b,c);
	
	z = ( a < b )? b :c;
	//		|		  |
	//		|		  If the satement isn't true then z = c
	//		|
	//		|
	//		If the statement here is true then z = b 
			
	printf("The answer is z=%d\r\n",z);
	
	
	return 0;
}