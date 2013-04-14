/*
	Tier 2 : Part 2	:	Question 2
	
	What is happening here is the variable has been given a static location in memory
	that is incremented each time , although the variable is declared each time
	C doesn't changed the last value at that location so it declares it with the value
	that was previously there
	
	so it counts it correctly to 100
*/
#include<stdio.h>

int main()
{
	int x,y;
	
	for( x=0; x<10; x++)
	{
 	 	for( y=0; y<10; y++)
 	 	{
 	 		  static int number_of_times = 0;
 	 		  number_of_times++;
			  printf("%d times around the loop\r\n",number_of_times);
 	 	}
		
	}
	
	return 0;
}