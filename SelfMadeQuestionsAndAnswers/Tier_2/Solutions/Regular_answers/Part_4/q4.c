/*
	Tier 2 : Part 4	:	Question 4
	
	Each time the user enters a number the function will return the Nth fibonacci number
	example 
	1=1
	2=1
	3=2
	4=3
	5=5
	6=8
	7=13
	8=21
*/
#include <stdio.h>

long func( long n ); 

int main()
{
   long result; 
   long number; 

   printf( "Enter an integer: " );
   scanf( "%ld", &number );
   result = func( number );
   printf( "\n func( %ld ) = %ld\n", number, result );
   
   return 0;

}

long func( long n )
{
	if ( n == 0 || n == 1 ) 
	{
		return n;
	} 
	else 
		{
			return func( n - 1 ) + func( n - 2 );
		} 
	
}