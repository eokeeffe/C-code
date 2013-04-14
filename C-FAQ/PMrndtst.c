/*
 *  Test program for Park and Miller's "Minimal standard" random number
 *  generator (see "Random Number Generators: Good Ones are Hard to Find
 *  CACM October 1988 Volume 31 Number 10 p. 1195)
 *
 *  Verifies 10001st term per expected value
 *
 *  Steve Summit 5/1995
 */

#include <stdio.h>

#ifdef oldway
#define U10001 1043618065L
#else
#define U10001 399268537L
#endif

#ifdef __STDC__
extern long int PMrand(void);
#endif

extern long int PMrand();

main()
{
	int n;
	long int u;

	for(n = 0; n < 10000; n++)
		u = PMrand();
	printf("z10001 = %ld\n", u);
	if(u == U10001)
		printf("(expected value; generator OK)\n");
	else	fprintf(stderr, "FAILURE (expected %ld)\n", U10001);
	return 0;
}
