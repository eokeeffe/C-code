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
 *  Based on the classic Abramowitz & Stegun algorithm
 *  (Handbook of Mathematical Functions)
 *  and suggestions by Arjun Ray.
 */

#include <stdlib.h>
#include <math.h>

#define PI 3.141592654


/* Abramowitz & Stegun */

#define ARJUN_RAY

#ifndef ARJUN_RAY

#ifdef NOSTATS
double gaussrand()
#else
double gaussrand(mean, stdev)
double mean, stdev;
#endif
{
	static double U, V;
	static int phase = 0;
	double Z;

	if(phase == 0) {
		U = (rand() + 1.) / (RAND_MAX + 2.);
		V = rand() / (RAND_MAX + 1.);
		Z = sqrt(-2 * log(U)) * sin(2 * PI * V);
	} else
		Z = sqrt(-2 * log(U)) * cos(2 * PI * V);

	phase = 1 - phase;

#ifdef NOSTATS
	return Z;
#else
	return mean + stdev * Z;
#endif
}

#else

/*
 *  From: Arjun Ray <aray@pipeline.com>
 *  Date: Sun, 26 Mar 1995 03:18:21 -0500
 *  Message-ID: <199503260818.DAA13871@pipe4.nyc.pipeline.com>
 */

#ifdef NOSTATS
double gaussrand()
#else
double gaussrand(mean, stdev)
double mean, stdev;
#endif
{
	static double radius, angle;
	static int phase = 0;
	double Z;

	if (phase == 0) {
		radius = sqrt(-2 * log((rand() + 1.) / (RAND_MAX + 2.)));
		angle = 2 * PI * rand() / (RAND_MAX + 1.);
		Z = radius * sin(angle) ;
	} else
		Z = radius * cos(angle) ;

	phase = 1 - phase;

#ifdef NOSTATS
	return Z;
#else
	return mean + stdev * Z;
#endif
}

#endif
