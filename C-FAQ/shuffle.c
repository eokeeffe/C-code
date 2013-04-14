/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 13.19)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

#ifdef __STDC__
int randrange(int);
int intcmp(const void *, const void *);
#endif

int intcmp();

main()
{
	int a[N], i, nvalues = N;

	srand((unsigned int)time((time_t *)NULL));

	/* shuffle an array containing the numbers 1..N, */
	/* to generate a random sequence in [1,N] with no repeats */

	for(i = 0; i < nvalues; i++)
		a[i] = i + 1;

	for(i = 0; i < nvalues-1; i++) {
		int c = randrange(nvalues-i);
		int t = a[i]; a[i] = a[i+c]; a[i+c] = t;	/* swap */
	}
	for(i = 0; i < N; i++)
		printf("%d\n", a[i]);

	/* verify shuffle by sorting back to original order */

	qsort(a, nvalues, sizeof(int), intcmp);

	for(i = 0; i < nvalues; i++)
		if(a[i] != i + 1)
			printf("oops: a[%d] = %d\n", i, a[i]);

	return 0;
}

randrange(int n)
{
	return rand() / (RAND_MAX / n + 1);
}

int intcmp(const void *p1, const void *p2)
{
	const int *ip1 = p1;
	const int *ip2 = p2;

	if(*ip1 < *ip2) return -1;
	else if(*ip1 > *ip2) return 1;
	else return 0;
}
