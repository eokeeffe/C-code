/*
	Tier 2 : Part 4	:	Question 1
*/
#include<stdio.h>

int  recurse ( int size )
{
  if ( size == 0 ){return 0; }// No recurse can be smaller than 1 
							// Return does not have to return something, it can be used
                            //  to exit a function
	return  recurse ( size - 1 ); // Decrements the size variable so the next recurse will be smaller.
}
int main()
{
	recurse ( 10 ); //Starts off with a large recurse (it's a logarithmic scale)
	return 0;	
}