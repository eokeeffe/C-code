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
 *
 *  #define MAIN for a standalone test version.
 */

#include <stdio.h>
#include <stdarg.h>
#ifdef MAIN

void miniprintf(char *, ...);

main()
{
	miniprintf("Hello, world!\n");
	miniprintf("%c %d %s\n", '1', 2, "three");
	miniprintf("%o %d %x\n", 10, 10, 10);
	miniprintf("%u\n", 0xffff);
	return 0;
}

#endif

extern char *baseconv(unsigned int, int);

void
miniprintf(char *fmt, ...)
{
	char *p;
	int i;
	unsigned u;
	char *s;
	va_list argp;

	va_start(argp, fmt);

	for(p = fmt; *p != '\0'; p++) {
		if(*p != '%') {
			putchar(*p);
			continue;
		}

		switch(*++p) {
		case 'c':
			i = va_arg(argp, int);
			/* *not* va_arg(argp, char); see Q <xref target=varargfloat> */
			putchar(i);
			break;

		case 'd':
			i = va_arg(argp, int);
			if(i < 0) {
				/* XXX won't handle INT_MIN */
				i = -i;
				putchar('-');
			}
			fputs(baseconv(i, 10), stdout);
			break;

		case 'o':
			u = va_arg(argp, unsigned int);
			fputs(baseconv(u, 8), stdout);
			break;

		case 's':
			s = va_arg(argp, char *);
			fputs(s, stdout);
			break;

		case 'u':
			u = va_arg(argp, unsigned int);
			fputs(baseconv(u, 10), stdout);
			break;

		case 'x':
			u = va_arg(argp, unsigned int);
			fputs(baseconv(u, 16), stdout);
			break;

		case '%':
			putchar('%');
			break;
		}
	}

	va_end(argp);
}
