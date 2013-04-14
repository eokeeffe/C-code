/*Evan O'Keeffe
  10324289
  practical 12 question 4
*/
#include<stdio.h>
#include<string.h>

#define A 10


int main()
{
	#if A 
	printf("part a #if works\r\n");
	#endif
	
	#ifdef A
	printf("part b #ifdef works\r\n");
	#endif
	
	#ifndef A
	printf("part c #if works\r\n");//doesn't show as the A is defined
	#endif
	
	#if defined (A)
	printf("part d #if works\r\n");
	#endif
	
	#if !defined(A)
	printf("part e #if works\r\n");//wont show as A is defined
	#endif
	
	return 0;
}