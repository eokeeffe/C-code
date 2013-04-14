/*
	Tier 2 : Part 8	:	Question 10
*/
#include<stdio.h>
#include<time.h>
#include "myheader_q10.h"


int main()
{
	#if __STDC__ == 1
	printf("This is Ansi C standardized\r\n");
	
	char return_key;
	double start_of_the_timer,end_of_the_timer,time_in_minutes,time_in_hours;
	
	start_of_the_timer = start_timer();
	
	printf("Timer started, press enter to get time since start of program\r\n");
	return_key=getchar();
	
	end_of_the_timer = end_timer(start_of_the_timer);
	printf("%lf was the number of seconds since you pressed enter\r\n",end_of_the_timer);
	
	time_in_minutes = minutes(end_of_the_timer);
	printf("%lf was the number of minutes since being stopped\r\n",time_in_minutes);
	
	time_in_hours = hours(time_in_minutes);
	printf("%lf was the number of hours since being stopped\r\n",time_in_hours);
	
	return 0;
	
	#else
		printf("This is not Ansi C standardized\r\n");
		return 0;
	#endif	
}