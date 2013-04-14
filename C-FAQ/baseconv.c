/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 20.10)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 *
 *  #define MAIN for a standalone test version, which reads
 *  lines of the form
 *
 *	n b
 *
 *  where n is a (decimal) number and b is the base it should
 *  be converted to.
 */

#include <stdio.h>
#include <limits.h>	/* for eventual safer retbuf[] size */

char *
baseconv(unsigned int num, int base)
{
	static char retbuf[33];
	char *p;

	if(base < 2 || base > 16)
		return NULL;

	p = &retbuf[sizeof(retbuf)-1];
	*p = '\0';

	do {
		*--p = "0123456789abcdef"[num % base];
		num /= base;
	} while(num != 0);

	return p;
}

#ifdef MAIN

#include <stdlib.h>

#ifdef __STDC__
extern int getline(FILE *, char *, int);
extern int makeargv(char *, char *[], int);
#endif

main()
{
char line[100];
char *av[3];
while(getline(stdin, line, (int)sizeof(line)) != EOF)
	{
	if(makeargv(line, av, (int)(sizeof(av)/sizeof(*av))) != 2)
		continue;

	printf("%s\n", baseconv(atoi(av[0]), atoi(av[1])));
	}

return 0;
}

#endif
