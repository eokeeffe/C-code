/*
	Tier 2 : Part 5	:	Question 2
*/
#include <stdio.h>
#include <stdlib.h>
 
int main()
{

  /* The (char) is a typecast, telling the computer to interpret the 65 as a
     character, not as a number.  It is going to give the character output of 
     the equivalent of the number 65 (It should be the letter A for ASCII).
     Note that the %c below is the format code for printing a single character
   */
	printf( "%c , %d\n", (char)65 , (int)'A');

	getchar();
}