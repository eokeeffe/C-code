/*
	Tier 2 : Part 9	:	Question 4
*/
#include<stdio.h>

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,0}; // sets the array to hold all of the numbers here but no more
	
	int *pa ;					   //a pointer to an integer
	
	pa = &a[0] ;				   // so the pointer now holds the location of the first element of the array
	
	printf("pa now contains %d in the memory location %d\r\n",*pa,pa);// as you would see the first number is 
																	  // what is at the location in memory
																	  // the second merely holds the memory location to go to
	
	return 0;
}