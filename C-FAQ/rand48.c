/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 13.21)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdlib.h>

#ifdef crudversion


double drand48()
{
	return rand() / (RAND_MAX + 1.);
}

#else

#define PRECISION 2.82e14	/* 2**48, rounded up */

double drand48()
{
	double x = 0;
	double denom = RAND_MAX + 1.;
	double need;

	for(need = PRECISION; need > 1;
			need /= (RAND_MAX + 1.)) {
		x += rand() / denom;
		denom *= RAND_MAX + 1.;
	}

	return x;
}

#endif
