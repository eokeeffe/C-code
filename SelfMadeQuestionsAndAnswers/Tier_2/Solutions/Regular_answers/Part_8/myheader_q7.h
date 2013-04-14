/* My Header file for question 7*/
#include<stdio.h>
#include<time.h> // for the CLOCKS_PER_SEC struct variable to be used

extern double start_timer();
extern double end_timer();
extern double minutes();
extern double hours();

extern double start_timer()
{
	return ((double)clock()); //get the number of cycles at start of the clock
}

extern double end_timer(double START_OF_CLOCK)
{
	return (((double)clock()-START_OF_CLOCK)/CLOCKS_PER_SEC);//get the current amount of cycles and divide by the initial to
															 //get the total amount of seconds
}

extern double minutes(double END_OF_CLOCK)
{
	return (END_OF_CLOCK/=60);
}

extern double hours(double minutes)
{
	return (minutes/=60);
}