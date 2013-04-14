/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 15.7)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdio.h>
#include <varargs.h>
#include <string.h>

extern char *malloc();

char *vstrcat(va_alist)
va_dcl		/* no semicolon */
{
	int len = 0;
	char *retbuf;
	va_list argp;
	char *p;

	va_start(argp);

	while((p = va_arg(argp, char *)) != NULL)	/* includes first */
		len += strlen(p);

	va_end(argp);

	retbuf = malloc(len + 1);		/* +1 for trailing \0 */

	if(retbuf == NULL)
		return NULL;			/* error */

	retbuf[0] = '\0';

	va_start(argp);			/* restart for second scan */

	while((p = va_arg(argp, char *)) != NULL)	/* includes first */
		strcat(retbuf, p);

	va_end(argp);

	return retbuf;
}
