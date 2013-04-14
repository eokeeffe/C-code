/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 20.8)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 */

#include <stdio.h>
#include <string.h>


#include <limits.h>		/* for CHAR_BIT */

#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

#ifdef __STDC__
int sieve(void);
#endif
int sieve();

main()
{
	char bitarray[BITNSLOTS(47)];
	BITSET(bitarray, 23);
	BITCLEAR(bitarray, 14);
	if(BITTEST(bitarray, 35))
		printf("yep\n");
	else	printf("nope\n");

	sieve();
	return 0;
}

void un(array1, array2, array3, N)
char array1[], array2[], array3[];
int N;
{
	int i;
	for(i = 0; i < BITNSLOTS(N); i++)
		array3[i] = array1[i] | array2[i];
}

#define MAX 100

sieve()
{
	char bitarray[BITNSLOTS(MAX)];
	int i, j;

	memset(bitarray, 0, BITNSLOTS(MAX));

	for(i = 2; i < MAX; i++) {
		if(!BITTEST(bitarray, i)) {
			printf("%d\n", i);
			for(j = i + i; j < MAX; j += i)
				BITSET(bitarray, j);
		}
	}
	return 0;
}
