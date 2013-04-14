/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 19.1)
 *
 *  Test program for tty_break(), tty_getchar(), etc. (tty_*.c)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdio.h>

#ifdef __STDC__
extern int tty_break(void);
extern int tty_getchar(void);
extern int tty_fix(void);
#endif

main()
{
	int i;
	if(tty_break() != 0)
		return 1;
	for(i = 0; i < 10; i++)
		printf(" = %d\n", tty_getchar());
	tty_fix();
	return 0;
}
