/*
	Tier 2 : Part 7	:	Question 1
	
	Information on compiler and operating system directives is
	refered from http://www.kohala.com/start/systype.h.sun.txt
	
*/
#include<stdio.h>
#include<string.h>


int main()
{
	
	char system_type[100];
	
	#ifdef	unix		/* true for most UNIX systems, BSD and Sys5 */
			/* but not for Xenix !! */
	#define	UNIX	1	/* OS type */

	#ifdef	vax		/* true for BSD on a VAX */
	/* also true for VAX Sys5, but we don't have to worry about that (for now) */
	#define	VAX	1	/* hardware */
	#define	BSD	1	/* OS type */
	#else
	#ifdef	sun

	#define	SUN	1	/* hardware */
	#define	BSD	1	/* OS type */
	#else
	#ifdef	pyr

	#define	PYRAMID	1	/* hardware */
	#define	BSD	1	/* OS type */
	#else
	#ifdef	mc68k		/* assume AT&T UNIX pc, aka 7300 or 3b1 */
				/* what about other 68000 unix systems ?? */
	#define	UNIXPC	1	/* hardware */
	#define	SYS5	1	/* OS type */
	#else
	#ifdef	i386		/* AT&T System V Release 3.2 on the Intel 80386 */

	#define	IBMPC	 1	/* hardware */
	#define	SYS5	 1	/* OS type */
	#else
	#ifdef	accel

	#define	CELERITY 1	/* hardware */
	#define	BSD	 1	/* OS type */
	#else
	what type of unix system is this
	#endif	/* accel */
	#endif	/* i386 */
	#endif	/* mc68k */
	#endif	/* pyr */
	#endif	/* sun */
	#endif	/* vax */

	#endif	/* unix */

	#ifdef	M_XENIX		/* true for SCO Xenix */
	#define	UNIX	1	/* OS type */
	#define	XENIX	1	/* OS type */
	#define	SYS5	1	/* OS type */
	#define	IBMPC	1	/* hardware */
	#endif	/* M_XENIX */

	#ifdef	MSDOS		/* true for Microsoft C and Lattice, assume former */
	#define	IBMPC		1	/* hardware */
	#define	MICROSOFT	1	/* C compiler type */
	#endif	/* MSDOS */
	
	
	#ifdef __unix32
		strcpy(system_type,"Linux 32 bit system , nice \r\n");
	#elif defined __unix64 
		strcpy(system_type,"Linux 64 bit system , bring on the tux rider \r\n");
	#elif defined _WIN32 // _WIN32 is defined by most compilers available for the Windows operating system (but not by all).
		strcpy(system_type,"Windows 32 bit system , nice\r\n");
	#elif defined _WIN64 
		strcpy(system_type,"Windows 64 bit system , nice and new\r\n");
	#endif

	printf("%s",system_type);
	return 0;
}