/*
	Tier 2 : Part 9	:	Question 5
*/
#include<stdio.h>

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,0};

	int *pa ;

	pa = a ;		// so if this works there is only one explanation
					// arrays must act the same way as pointers
					// which is true , all arrays are is sequential memory locations
					// the expression a[0] is the same as a as they both point to the first 
					// location of the array 
	
	printf("%d is held in pa in memory location %d\r\n",*pa,pa);
	return 0;
}