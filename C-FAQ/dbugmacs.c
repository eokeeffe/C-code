/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 10.27)
 *
 *  Based on ideas suggested by several netters.
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdio.h>
#include <stdarg.h>

void debug(char *fmt, ...);
void dbginfo1(int, char *);
#define DEBUG1 dbginfo1(__LINE__, __FILE__), debug

static char *dbgfile;
static int dbgline;

void dbginfo1(int line, char *file)
{
	dbgfile = file;
	dbgline = line;
}

void debug(char *fmt, ...)
{
	va_list argp;
	fprintf(stderr, "DEBUG: \"%s\", line %d: ", dbgfile, dbgline);
	va_start(argp, fmt);
	vfprintf(stderr, fmt, argp);
	va_end(argp);
	fprintf(stderr, "\n");
}

void (*dbginfo2(int, char *))(char *, ...);
#define DEBUG2 (*dbginfo2(__LINE__, __FILE__))

void (*dbginfo2(int line, char *file))(char *, ...)
{
	dbgfile = file;
	dbgline = line;
	return debug;
}

main()
{
int i = 1;
DEBUG1("Hello, world! %d", i++);
DEBUG2("Hello, world! %d", i++);
return 0;
}
