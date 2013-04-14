/*
	Tier 2 : Part 8	:	Question 6
*/
#include "myheader_q6.h"

int main()
{
	char return_key;
	double start_of_the_timer;
	
	start_of_the_timer = start_timer();
	
	printf("Timer started, press enter to get time since start of program\r\n");
	return_key=getchar();
	
	printf("%lf was the number of seconds since you pressed enter\r\n",end_timer(start_of_the_timer));
	
	return 0;
}