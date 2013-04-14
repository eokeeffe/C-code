/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (questions 13.8 and 13.9)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdio.h>
#include <string.h>

/* compare strings via pointers */
int pstrcmp(const void *p1, const void *p2)
{
	return strcmp(*(char * const *)p1, *(char * const *)p2);
}

#define NSTRINGS 10

void test1()
{
int i;
#include <stdlib.h>
char *strings[NSTRINGS];
int nstrings;
strings[0] = "This";
strings[1] = "is";
strings[2] = "a";
strings[3] = "test";
nstrings = 4;
/* nstrings cells of strings[] are to be sorted */
qsort(strings, nstrings, sizeof(char *), pstrcmp);
for(i = 0; i < nstrings; i++)
	printf("%s\n", strings[i]);
}

struct mystruct {
	int year, month, day;
};

int mystructcmp(const void *p1, const void *p2)
{
	const struct mystruct *sp1 = p1;
	const struct mystruct *sp2 = p2;
	/* now compare sp1-&gt;whatever and sp2-&gt; ... */
	if(sp1->year < sp2->year) return -1;
	else if(sp1->year > sp2->year) return 1;
	else if(sp1->month < sp2->month) return -1;
	else if(sp1->month > sp2->month) return 1;
	else if(sp1->day < sp2->day) return -1;
	else if(sp1->day > sp2->day) return 1;
	else return 0;
}

#define NDATES 10

#include <stdlib.h>
struct mystruct dates[NDATES];
int ndates;

void test2()
{
int i;

dates[0].year = 1995; dates[0].month = 10; dates[0].day = 2;
dates[1].year = 1994; dates[1].month = 10; dates[1].day = 1;
dates[2].year = 1996; dates[2].month = 1; dates[2].day = 1;
dates[3].year = 1995; dates[3].month = 10; dates[3].day = 1;
dates[4].year = 1994; dates[4].month = 10; dates[4].day = 1;
dates[5].year = 1900; dates[5].month = 1; dates[5].day = 1;

ndates = 6;

/* ndates cells of dates[] are to be sorted */
qsort(dates, ndates, sizeof(struct mystruct), mystructcmp);

for(i = 0; i < ndates; i++)
	printf("%d/%d/%d\n", dates[i].month, dates[i].day, dates[i].year);
}

int myptrstructcmp(const void *p1, const void *p2)
{
	struct mystruct *sp1 = *(struct mystruct * const *)p1;
	struct mystruct *sp2 = *(struct mystruct * const *)p2;

	if(sp1->year < sp2->year) return -1;
	else if(sp1->year > sp2->year) return 1;
	else if(sp1->month < sp2->month) return -1;
	else if(sp1->month > sp2->month) return 1;
	else if(sp1->day < sp2->day) return -1;
	else if(sp1->day > sp2->day) return 1;
	else return 0;
}

void test3()
{
int i;

struct mystruct *dateptrs[NDATES];
int ndates;

dateptrs[0] = &dates[4];
dateptrs[1] = &dates[2];
dateptrs[2] = &dates[1];
dateptrs[3] = &dates[3];
dateptrs[4] = &dates[0];
dateptrs[5] = &dates[5];

ndates = 6;

for(i = 0; i < ndates; i++)
	printf("%d/%d/%d\n", dateptrs[i]->month, dateptrs[i]->day, dateptrs[i]->year);

qsort(dateptrs, ndates, sizeof(struct mystruct *), myptrstructcmp);

for(i = 0; i < ndates; i++)
	printf("%d/%d/%d\n", dateptrs[i]->month, dateptrs[i]->day, dateptrs[i]->year);
}

main()
{
test1();
printf("\n");
test2();
printf("\n");
test3();
return 0;
}
