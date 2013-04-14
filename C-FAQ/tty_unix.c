/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 19.1)
 *
 *  System-specific terminal-handling code:
 *  this version for "classic" Unix (V7, BSD, etc.)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdio.h>
#include <sgtty.h>

static struct sgttyb savemodes;
static int havemodes = 0;

int tty_break()
{
	struct sgttyb modmodes;
	if(ioctl(fileno(stdin), TIOCGETP, &savemodes) < 0)
		return -1;
	havemodes = 1;
	modmodes = savemodes;
	modmodes.sg_flags |= CBREAK;
	return ioctl(fileno(stdin), TIOCSETN, &modmodes);
}

int tty_getchar()
{
	return getchar();
}

int tty_fix()
{
	if(!havemodes)
		return 0;
	return ioctl(fileno(stdin), TIOCSETN, &savemodes);
}
