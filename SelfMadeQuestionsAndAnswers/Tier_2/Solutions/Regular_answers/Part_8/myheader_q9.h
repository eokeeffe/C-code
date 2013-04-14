/* My Header file for question 9*/
//check if stdio.h is already included
#ifdef _STDIO_H_

#else
	#include<stdio.h> // for the CLOCKS_PER_SEC struct variable to be used
#endif
//test if time.h has already been included
#ifdef _TIME_H_
	
#else
	#include<time.h> // for the CLOCKS_PER_SEC struct variable to be used
#endif
//this will require some expalanation
//when defining a header file the name has to be in highercase and the spaces have
//to be replaced with the two under scores '__' for non standardazied header files
//all thats happening is that the pre-processor will check each of these and only include the 
//header files if they haven't already been included
#ifdef __MYHEADER_Q9_H_
	
#else 
	#define __MYHEADER_Q9_H_
#endif

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