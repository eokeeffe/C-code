/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 7.30)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdio.h>
#include <stdlib.h>

/* read a line from fp into malloc'ed memory */
/* returns NULL on EOF or error */
/* (use feof or ferror to distinguish) */

char *agetline(FILE *fp)
{
	char *retbuf = NULL;
	size_t nchmax = 0;
	register int c;
	size_t nchread = 0;
	char *newbuf;

	while((c = getc(fp)) != EOF) {
		if(nchread >= nchmax) {
			nchmax += 20;
#ifdef SAFEREALLOC
			newbuf = realloc(retbuf, nchmax + 1);
#else
			if(retbuf == NULL)	/* in case pre-ANSI realloc */
				newbuf = malloc(nchmax + 1);
			else	newbuf = realloc(retbuf, nchmax + 1);
#endif
						/* +1 for \0 */
			if(newbuf == NULL) {
				free(retbuf);
				return NULL;
			}

			retbuf = newbuf;
		}

		if(c == '\n')
			break;

		retbuf[nchread++] = c;
	}

	if(retbuf != NULL) {
		retbuf[nchread] = '\0';

		newbuf = realloc(retbuf, nchread + 1);
		if(newbuf != NULL)
			retbuf = newbuf;
	}

	return retbuf;
}
