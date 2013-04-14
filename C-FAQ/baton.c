/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 19.3)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdio.h>

#ifdef __STDC__
void do_timeconsuming_work(void);
#endif
void do_timeconsuming_work();

main()
{
	int i;
	int lotsa = 50;

	for(i = 0; i < lotsa; i++) {
		printf("\r%3d%%", (int)(100L * i / lotsa));
		fflush(stdout);
		do_timeconsuming_work();
	}
	printf("\ndone.\n");

	printf("working: ");
	for(i = 0; i < lotsa; i++) {
		printf("%c\b", "|/-\\"[i%4]);
		fflush(stdout);
		do_timeconsuming_work();
	}
	printf("done.\n");

	return 0;
}

#include <math.h>

void do_timeconsuming_work()
{
	int i;
	for(i = 0; i <= 360; i++)
		sin(3.14159 * i / 180);
}
