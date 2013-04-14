/*
	Tier 2 : Part 5	:	Question 9
*/
#include <stdio.h>

float divide(int dividend,int divisor)
{
	return ( (float) dividend / divisor );
	//in short there is nothing wrong with the casting , you'll get the right number
	//for small amounts 
	//It will however effect the accuracy as the division is done on a float with an int
	//so any division on the decimal points will not occur 
	// a way to fix this is obviously cast the two ints to floats
	//
	// return ( (float) dividend / (float)divisor );
} 

int main()
{
	int dividend=4, divisor=20;
	
	printf("%f is the answer \r\n",divide(dividend , divisor));
	
	return 0;
}