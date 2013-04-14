/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 20.12)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 *
 *  #define MAIN for a standalone test version, which reads
 *  numbers and then prints them back out in hexadecimal,
 *  along with their bit counts.
 */

static int bitcounts[] =
	{0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

int bitcount(unsigned int u)
{
	int n = 0;

	for(; u != 0; u >>= 4)
		n += bitcounts[u & 0x0f];

	return n;
}
#ifdef MAIN

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

main()
{
char line[MAXLINE];
unsigned int u;

while(1)
	{
	printf("? ");
	fflush(stdout);

	if(fgets(line, MAXLINE, stdin) == NULL)
		break;

	u = strtoul(line, (char **)NULL, 0);

	printf("%u (%x): %d\n", u, u, bitcount(u));
	}

return 0;
}

#endif
