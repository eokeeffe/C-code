/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 20.2)
 *
 *  The principal code from question 20.2 is in the function
 *  readlines(); the rest of this file is test scaffolding.
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __STDC__
int readlines(FILE *, char ***);
void printlines(char **, int);
void freelines(char **, int);
extern char *agetline(FILE *);
#endif

void printlines();
void freelines();

extern char *agetline();

char *a[4] = {"this", "is", "a", "test"};
char **p = a;

main()
{
printlines(p, 4);

{

char **p = malloc(4 * sizeof(char *));
if(p != NULL) {
	p[0] = malloc(5);
	p[1] = malloc(3);
	p[2] = malloc(2);
	p[3] = malloc(5);

	if(p[0] && p[1] && p[2] && p[3]) {
		strcpy(p[0], "this");
		strcpy(p[1], "is");
		strcpy(p[2], "a");
		strcpy(p[3], "test");
	}
}

printlines(p, 4);
}

while(1)
	{
	char **lines;
	int nlines;
	nlines = readlines(stdin, &lines);
	if(nlines == 0)
		break;
	printlines(lines, nlines);
	freelines(lines, nlines);
	clearerr(stdin);
	}

return 0;
}

readlines(ifp, linesp)
FILE *ifp;
char ***linesp;
{

/* assume ifp is open on input file */

char **lines = NULL;
size_t nalloc = 0;
size_t nlines = 0;
char *p;

while((p = agetline(ifp)) != NULL) {
	if(nlines >= nalloc) {
		nalloc += 50;
#ifdef SAFEREALLOC
		lines = realloc(lines, nalloc * sizeof(char *));
#else
		if(lines == NULL)		/* in case pre-ANSI realloc */
			lines = malloc(nalloc * sizeof(char *));
		else	lines = realloc(lines, nalloc * sizeof(char *));
#endif
		if(lines == NULL) {
			fprintf(stderr, "out of memory");
			exit(1);
		}
	}

	lines[nlines++] = p;
}

*linesp = lines;

return nlines;
}

void
printlines(lines, nlines)
char **lines;
int nlines;
{
	int i;
	for(i = 0; i < nlines; i++)
		printf("%d \"%s\" (%d)\n", i, lines[i], (int)strlen(lines[i]));
}

void
freelines(lines, nlines)
char **lines;
int nlines;
{
	int i;
	for(i = 0; i < nlines; i++)
		free(lines[i]);
	free(lines);
}
