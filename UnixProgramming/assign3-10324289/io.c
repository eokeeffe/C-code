#include<stdio.h>
#include "convert.h"

/*
	EOK
	10324289
	io.c
*/

//print the table for acres to square feet
extern void printTableX(double lower,double upper)
{
	
	if((upper)-(lower) <= num_steps-1)
	{
		fprintf(stderr,"%lf %lf\r\n",lower,upper);
		fprintf(stderr,"Bounds to low!\r\n");
		return;
	}

	double count;
	int step_size = (upper-lower)/(num_steps-1);
	
	fprintf(stdout,"|------------||------------|\r\n");
	fprintf(stdout,"|Acres       ||Square Feet |\r\n");
	fprintf(stdout,"|------------||------------|\r\n");
	for(count=lower;count<=upper;count += step_size)
	{
		fprintf(stdout,"|%12.2lf||%12.2lf|\r\n",count,convertxToy(count));
	}
}

//print the square feet to acres table
extern void printTableY(double lower,double upper)
{
	if((upper)-(lower) <= num_steps-1)
	{
		fprintf(stderr,"%lf %lf\r\n",lower,upper);
		fprintf(stderr,"Bounds to low!\r\n");
		return;
	}

	double count;
	int step_size = (upper-lower)/(num_steps-1);

	fprintf(stdout,"|-----------\t||-----\t\t|\r\n");
	fprintf(stdout,"|Square Feet\t||Acres\t\t|\r\n");
	fprintf(stdout,"|-----------\t||-----\t\t|\r\n");
	for(count=lower;count<= upper;count += step_size)
	{
		fprintf(stdout,"|%12.2lf\t||%e\t|\r\n",count,convertyTox(count));
	}
}

//my own stdin flush function , portable and safe
extern void flushStdin()
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
	//reset the stdin buffer marker back to zero
	clearerr(stdin);
}

extern double input()
{
	double user_input=0.0;
	//while scanf gets a correct input
	//clean the buffer and try again
	//scanf is documented to have a return value of
	//the number of inputs it will recieve
	while( scanf("%lf",&user_input) != 1)
	{
		fprintf(stderr,"Please enter a float\r\n");
		flushStdin();
	}
	return user_input;
}
