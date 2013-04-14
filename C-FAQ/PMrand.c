/*
 *  "Minimal standard" pseudo-random number generator
 *  from
 *  Park and Miller
 *  "Random Number Generators: Good Ones are Hard to Find
 *  CACM October 1988 Volume 31 Number 10 p. 1195
 *
 *  This implementation by Steve Summit for the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 13.15)
 */

#ifdef oldway
#define a 16807
#else
#define a 48271
#endif
#define m 2147483647
#define q (m / a)
#define r (m % a)

static long int seed = 1;


#ifdef notdef

long int PMrand()
{
	seed = (a * seed) % m;
	return seed;
}

#else

long int PMrand()
{
	long int hi = seed / q;
	long int lo = seed % q;
	long int test = a * lo - r * hi;
	if(test > 0)
		seed = test;
	else	seed = test + m;
	return seed;
}

#endif
