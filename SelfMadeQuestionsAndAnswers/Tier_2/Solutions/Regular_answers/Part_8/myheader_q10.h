/* My Header file for question 10*/
//check if stdio.h is already included
#ifdef _STDIO_H_

#else
	#include<stdio.h> // for the CLOCKS_PER_SEC struct variable to be used
#endif
//test if time.h has already been included
#ifdef _TIME_H_
//test to see if the program is C++ or C and add the appropriate header file
#elif ifndef _TIME_H_
	#ifdef __cplusplus
		#include<ctime>  //for c++ users
	#else
		#include<time.h> //for c users
	#endif
#endif
//this will require some expalanation
//when defining a header file the name has to be in highercase and the spaces have
//to be replaced with the two under scores '__' for non standardazied header files
//all thats happening is that the pre-processor will check each of these and only include the 
//header files if they haven't already been included
#ifdef __MYHEADER_Q10_H_
	
#else 
	#define __MYHEADER_Q10_H_
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

/*Example use for C users
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
*/


/*Example use for C++ users

    double start,end;   //declare 2 variables
    std::string begin;  //declare a string to show real time usage
    std::cout<<"StopWatch will start on entering something"<<std::endl;
    std::cin >> begin;
    start=start_timer();//starts the timer , start_timer will return the clock speed from the cpu

    std::cout<<"StopWatch will end when "<<std::endl;
    std::cin >> begin;
    end = end_timer(start); //this will return what the resulting time will be from start to now

    std::cout<<"Time taken is "<< end <<" seconds"<<std::endl;
    std::cin >> begin;

*/
