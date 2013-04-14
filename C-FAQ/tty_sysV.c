/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 19.1)
 *
 *  System-specific terminal-handling code:
 *  this version for System V Unix.
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdio.h>
#include <termio.h>

/* based on Horton, Portable C Software, chapter 10, pp. 128-9 */


static struct termio savemodes;
static int havemodes = 0;

int tty_break()
{
	struct termio modmodes;
	if(ioctl(fileno(stdin), TCGETA, &savemodes) < 0)
		return -1;
	havemodes = 1;
	modmodes = savemodes;
	modmodes.c_lflag &= ~ICANON;
	modmodes.c_cc[VMIN] = 1;
	modmodes.c_cc[VTIME] = 0;
	return ioctl(fileno(stdin), TCSETAW, &modmodes);
}

int tty_getchar()
{
	return getchar();
}

int tty_fix()
{
	if(!havemodes)
		return 0;
	return ioctl(fileno(stdin), TCSETAW, &savemodes);
}
