/*
	EOK
	10324289
	declarations for all the io functions
*/
#ifndef IO_H_
	#define IO_H_
	//print the Acres to Square Feet table
	extern void printTableX(double lower,double upper);
	//print the Square feet to Acres table
	extern void printTableY(double lower,double upper);
	//my function to flush stdin buffer
	extern void flushStdin();
	//user input function
	extern double input();
#endif
