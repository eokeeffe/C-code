/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 13.7)
 *
 *  Based on code by Arjan Kenter, posted to Usenet comp.lang.c
 *  on 13 Jan 1995 (message-id <3f65s7$li9@utrhcs.cs.utwente.nl>)
 *
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 *
 *  #define MAIN for a standalone test version, which reads
 *  lines consisting of a pattern and a string, printing "yes"
 *  if they match.
 */

int match(char *pat, char *str)
{
	switch(*pat) {
	case '\0':  return !*str;
	case '*':   return match(pat+1, str) ||
				*str && match(pat, str+1);
	case '?':   return *str && match(pat+1, str+1);
	default:    return *pat == *str && match(pat+1, str+1);
	}
}

#ifdef MAIN

#include <stdio.h>

#define MAXLINE 100

#ifdef __STDC__
extern int getline(FILE *, char *, int);
extern int makeargv(char *, char *[], int);
#endif

main()
{
char line[MAXLINE];
char *av[3];

while(getline(stdin, line, MAXLINE) != EOF)
	{
	if(makeargv(line, av, 3) < 2)
		continue;
	printf("%s\t%s\t%s\n", av[0], av[1], match(av[0], av[1]) ? "yes" : "no");
	}

return 0;
}

#endif
