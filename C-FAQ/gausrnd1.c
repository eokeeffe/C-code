/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 13.20)
 *
 *  Based on a well-known algorithm, and ideas
 *  suggested by several netters.
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdlib.h>
#include <math.h>

#define NSUM 25

#ifdef NOSTATS
double gaussrand()
#else
double gaussrand(mean, stdev)
double mean, stdev;
#endif
{
	double x = 0;
	int i;
	for(i = 0; i < NSUM; i++)
		x += (double)rand() / RAND_MAX;

	x -= NSUM / 2.0;
	x /= sqrt(NSUM / 12.0);

#ifdef NOSTATS
	return x;
#else
	return mean + stdev * x;
#endif
}
