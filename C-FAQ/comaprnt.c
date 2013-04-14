/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 12.11)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 *
 *  #define MAIN for a standalone test version, which reads
 *  numbers and then prints them back out with commas inserted.
 */

#include <string.h>
#ifndef oldway
#include <limits.h>
#endif
#include <locale.h>

char *commaprint(unsigned long n)
{
	static int comma = '\0';
	static char retbuf[30];
	char *p = &retbuf[sizeof(retbuf)-1];
	int i = 0;
#ifndef oldway
	static char *grouping = NULL;
	char *gp;
#endif
	memset(retbuf, 'x', sizeof retbuf);

	if(comma == '\0') {
		struct lconv *lcp = localeconv();
		if(lcp != NULL) {
			if(lcp->thousands_sep != NULL &&
				*lcp->thousands_sep != '\0')
				comma = *lcp->thousands_sep;
			else	comma = ',';
#ifndef oldway
			if(lcp->grouping != NULL &&
				*lcp->grouping != '\0')
				grouping = lcp->grouping;
			else	grouping = "\3";
#endif
		}
	}

	*p = '\0';
#ifndef oldway
	gp = grouping;
#endif

	do {
#ifdef oldway
		if(i%3 == 0 && i != 0)
#else
		if(*gp != 0 && *gp != CHAR_MAX && i%*gp == 0 && i != 0) {
#endif
			*--p = comma;
#ifndef oldway
			if(*(gp+1) != 0) {
				gp++;
				i = 0;
			}
		}
#endif
		*--p = '0' + n % 10;
		n /= 10;
		i++;
	} while(n != 0);

	return p;
}

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

main()
{
char line[MAXLINE];
setlocale(LC_ALL, "");
while(1)
	{
	printf("? ");
	fflush(stdout);

	if(fgets(line, MAXLINE, stdin) == NULL)
		break;

	printf("\"%s\"\n", commaprint(atol(line)));
	}

return 0;
}
