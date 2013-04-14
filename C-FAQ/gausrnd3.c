/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 13.20)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 *
 *  Based on the classic Box/Muller algorithm,
 *  as discussed in Knuth, The Art of Computer Programming
 *  Volume 2 (Second Edition) section 3.4.1 C, page 117.
 */

#include <stdlib.h>
#include <math.h>

#ifdef NOSTATS
double gaussrand()
#else
double gaussrand(mean, stdev)
double mean, stdev;
#endif
{
	static double V1, V2, S;
	static int phase = 0;
	double X;

	if(phase == 0) {
		do {
			double U1 = (double)rand() / RAND_MAX;
			double U2 = (double)rand() / RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
			} while(S >= 1 || S == 0);

		X = V1 * sqrt(-2 * log(S) / S);
	} else
		X = V2 * sqrt(-2 * log(S) / S);

	phase = 1 - phase;

#ifdef NOSTATS
	return X;
#else
	return mean + stdev * X;
#endif
}
