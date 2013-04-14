/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 15.5)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 *
 *  #define MAIN for a standalone test version.
 */

#include <stdio.h>
#ifndef VARARGS
#include <stdarg.h>

#ifdef __STDC__
void error(char *fmt, ...)
#else
void error(fmt)
char *fmt;
#endif
{
	va_list argp;
	fprintf(stderr, "error: ");
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp);
	fprintf(stderr, "\n");
}
#else
#include <varargs.h>

void error(va_alist)
va_dcl		/* no semicolon */
	{
	char *fmt;
	va_list argp;
	fprintf(stderr, "error: ");
	va_start(argp);
	fmt = va_arg(argp, char *);
	vfprintf(stderr, fmt, argp);
	va_end(argp);
	fprintf(stderr, "\n");
}
#endif
#ifdef MAIN

main()
{
	error("Hello, world!");
	error("%d != %s", 1, "two");
	return 0;
}

#endif
