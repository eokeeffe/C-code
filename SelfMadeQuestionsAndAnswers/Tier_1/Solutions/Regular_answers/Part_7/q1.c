/*
	Tier 1 : Part 7	:	Question 1
	
	The main look here is how parenthesis is crucial to getting 
	accurate results in the program 
	
	The equation without the parenthesis will have the number -126 printed out 
	whereas the one with parenthesis will give the result we are looking for 
	at 381
	
	In essence ALWAYS USE PARENTHESIS
*/
#include<stdio.h>
#include<stdlib.h>

//defines below
#define x 5*7+2-8
#define y 10*2-8+1

int main()
{
	printf("%d from the first equation\r\n",(x*y+4));
	printf("%d from the second equation\r\n",(((x)*(y))+4) );
	
	return 0;
}