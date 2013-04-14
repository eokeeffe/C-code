/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 15.12)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 *
 *  #define MAIN for a standalone test version.
 */

#include <stdio.h>
#include <stdarg.h>

void verror(char *fmt, va_list argp)
{
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, argp);
	fprintf(stderr, "\n");
}

void error(char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	verror(fmt, argp);
	va_end(argp);
}

#include <stdlib.h>

void faterror(char *fmt, ...)
{
	va_list argp;
	va_start(argp, fmt);
	verror(fmt, argp);
	va_end(argp);
	exit(EXIT_FAILURE);
}

#ifdef MAIN

main()
{
	error("Hello, world!");
	error("%d != %s", 1, "two");
	faterror("This is error number %d", 3);
	faterror("can't happen");
	return 0;
}

#endif
