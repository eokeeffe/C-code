/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 14.11)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdio.h>
#include "complex.h"

complex cpx_make(double real, double imag)
{
	complex ret;
	ret.real = real;
	ret.imag = imag;
	return ret;
}

complex cpx_add(complex a, complex b)
{
	return cpx_make(Real(a) + Real(b), Imag(a) + Imag(b));
}

complex cpx_subtract(complex a, complex b)
{
	return cpx_make(Real(a) - Real(b), Imag(a) - Imag(b));
}

complex cpx_multiply(complex a, complex b)
{
	return cpx_make(Real(a) * Real(b) - Imag(a) * Imag(b),
		Real(a) * Imag(b) + Imag(a) * Real(b));
}

char *
cpx_print(char *fmt, complex a)
{
	static char retbuf[30];
	char *p;
	sprintf(retbuf, fmt, Real(a));
	for(p = retbuf; *p != '\0'; p++)
		;
	*p++ = '+';
	sprintf(p, fmt, Imag(a));
	for(; *p != '\0'; p++)
		;
	*p++ = 'i';
	*p = '\0';
	return retbuf;
}
