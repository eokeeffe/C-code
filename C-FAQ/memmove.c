/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 11.25)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 *
 *  #define MAIN for a standalone test version.
 */

#include <stddef.h>

#define memmove mymemmove

void *memmove(void *dest, void const *src, size_t n)
{
	register char *dp = dest;
	register char const *sp = src;
	if(dp < sp) {
		while(n-- > 0)
			*dp++ = *sp++;
	} else {
		dp += n;
		sp += n;
		while(n-- > 0)
			*--dp = *--sp;
	}

	return dest;
}

#ifdef MAIN

#include <stdio.h>

main()
{
	char a[] = "This is a test.";
	char b[20];

	printf("%s\n", (char *)memmove(b, a, sizeof(a)));
	memmove(&b[9], &b[10], 4);
	printf("%s\n", b);
	memmove(&b[10], &b[9], 4);
	printf("%s\n", b);
	printf("%s\n", a);
	return 0;
}

#endif
