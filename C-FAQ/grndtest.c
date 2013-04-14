/*
 *  Test program for Gaussian random number generator(s)
 *  Prints histogram; computes statistics
 *
 *  scs 6/1/1995
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#ifdef mac
#include <console.h>
#endif
#include "defs.h"

#define WIDTH 65

int printallvals = FALSE;

#ifdef __STDC__
#ifdef NOSTATS
extern double gaussrand(void);
#else
extern double gaussrand(double, double);
#endif
#endif
extern double gaussrand();

main(argc, argv)
int argc;
char *argv[];
{
int nsamp = 1000;

double mean = 0;
double stdev = 1;

int i;

double sumx, sumxsq;
int n;

int nbuckets = 0;
double bucketquant = 0.0;
int *buckets;
int underflow = FALSE, overflow = FALSE;
int max;
double scale;

char *buckfmt = "% 5.0f";

#ifdef mac
argc = ccommand(&argv);
#endif

for(i = 1; i < argc && argv[i][0] == '-'; i++)
	{
	char *p;
	for(p = &argv[i][1]; *p != '\0'; p++)
		{
		switch(*p)
			{
			case 'b':
				if(*(p+1) == 'q')
					{
					bucketquant = atof(argv[++i]);
					p++;
					}
				else	{
					nbuckets = atoi(argv[++i]);
					}
				break;

			case 'm':
				mean = atof(argv[++i]);
				break;

			case 'n':
				if(*(p+1) == 'b')
					{
					nbuckets = atoi(argv[++i]);
					p++;
					}
				else	{
					nsamp = atoi(argv[++i]);
					}
				break;

			case 'p':
				printallvals = TRUE;
				break;

			case 's':
				stdev = atof(argv[++i]);
				break;

			default:
				fprintf(stderr, "unknown option -%c\n", *p);
			}
		}
	}

if(i < argc)
	nsamp = atoi(argv[i++]);

if(nbuckets == 0)
	nbuckets = 21;

if(bucketquant == 0.0)
	bucketquant = 10 * stdev / (nbuckets - 1);

if(bucketquant < 1 || (int)bucketquant != bucketquant)
	{
	if(nbuckets <= 20)
		buckfmt = "% 5.1f";
	else	buckfmt = "% 5.2f";
	}

buckets = malloc(nbuckets * sizeof(int));
if(buckets == NULL)
	{
	fprintf(stderr, "out of memory\n");
	exit(1);
	}

for(i = 0; i < nbuckets; i++)
	buckets[i] = 0;

sumx = sumxsq = 0;
n = 0;

srand((unsigned int)time((time_t *)NULL));

for(i = 0; i < nsamp; i++)
	{
	int b;
	double x = gaussrand(mean, stdev);
	if(printallvals)
		printf("% g\n", x);
	sumx += x;
	sumxsq += x * x;
	n++;

	b = (x - mean) / bucketquant + (nbuckets-1) / 2.0 + 0.5;
	if(b < 0)
		{
		underflow = TRUE;
		b = 0;
		}
	else if(b >= nbuckets)
		{
		overflow = TRUE;
		b = nbuckets - 1;
		}

	buckets[b]++;
	}

printf("actual mean = %g, std. dev. = %g\n", sumx / n,
	sqrt((sumxsq - sumx*sumx/n) / (n - 1)));

max = 0;

for(i = 0; i < nbuckets; i++)
	{
	if(buckets[i] > max)
		max = buckets[i];
	}

scale = (double)max / WIDTH;

for(i = 0; i < nbuckets; i++)
	{
	int bb, ii;
	int c = '*';

	printf("%2d ", i);
	printf(buckfmt, (i - (nbuckets - 1) / 2.0) * bucketquant + mean);
	printf(" %4d ", buckets[i]);
	bb = buckets[i] / scale;
	/* if(bb == 0 && buckets[i] > 0)
		bb = 1; */
	if(i == 0 && underflow)
		c = '#';
	else if (i == nbuckets-1 && overflow)
		c = '#';
	for(ii = 0; ii < bb; ii++)
		putchar(c);
	printf("\n");
	}

return 0;
}
