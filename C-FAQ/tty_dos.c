/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 19.1)
 *
 *  System-specific terminal-handling code:
 *  this version for MS-DOS.
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

int tty_break() { return 0; }

int tty_getchar()
{
	return getche();
}

int tty_fix() { return 0; }
