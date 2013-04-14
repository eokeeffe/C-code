/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 15.4)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdlib.h>		/* for malloc, NULL, size_t */
#include <stdarg.h>		/* for va_ stuff */
#include <string.h>		/* for strcat et al. */

char *vstrcat(char *first, ...)
{
	size_t len;
	char *retbuf;
	va_list argp;
	char *p;

	if(first == NULL)
		return NULL;

	len = strlen(first);

	va_start(argp, first);

	while((p = va_arg(argp, char *)) != NULL)
		len += strlen(p);

	va_end(argp);

	retbuf = malloc(len + 1);	/* +1 for trailing \0 */

	if(retbuf == NULL)
		return NULL;		/* error */

	(void)strcpy(retbuf, first);

	va_start(argp, first);		/* restart for second scan */

	while((p = va_arg(argp, char *)) != NULL)
		(void)strcat(retbuf, p);

	va_end(argp);

	return retbuf;
}
