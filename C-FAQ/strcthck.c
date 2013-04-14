/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 2.6)
 *
 *  Several variations of the infamous "struct hack"
 *  ("unwarranted chumminess with the compiler"),
 *  suggested in part by Mark Brader.
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdlib.h>
#include <string.h>


/* the traditional struct hack */

struct name1 {
	int namelen;
	char namestr[1];
};

struct name1 *makename1(char *newname)
{
	struct name1 *ret =
		malloc(sizeof(struct name1)-1 + strlen(newname)+1);
				/* -1 for initial [1]; +1 for \0 */
	if(ret != NULL) {
		ret->namelen = strlen(newname);
		strcpy(ret->namestr, newname);
	}

	return ret;
}

/* slightly modified: namestr[] array too large rather than too small */

#define MAXSIZE 100

struct name2 {
	int namelen;
	char namestr[MAXSIZE];
};

struct name2 *makename2(char *newname)
{
	struct name2 *ret =
		malloc(sizeof(struct name2)-MAXSIZE+strlen(newname)+1);
								/* +1 for \0 */
	if(ret != NULL) {
		ret->namelen = strlen(newname);
		strcpy(ret->namestr, newname);
	}

	return ret;
}

/* two separate allocations; namep pointer rather than namestr array */
/* assuredly portable; no longer a hack (requires two free's, though) */

struct name3 {
	int namelen;
	char *namep;
};

struct name3 *makename3(char *newname)
{
	struct name3 *ret = malloc(sizeof(struct name3));
	if(ret != NULL) {
		ret->namelen = strlen(newname);
		ret->namep = malloc(ret->namelen + 1);
		if(ret->namep == NULL) {
			free(ret);
			return NULL;
		}
		strcpy(ret->namep, newname);
	}

	return ret;
}

/*
 *  Following based on suggestions from Mark Brader:
 *
 *  Date: Mon, 15 May 1995 03:59:54 -0400
 *  From: msb@sq.com
 *  Message-Id: <9505150759.AA11520@sqrex.sq.com>
 */

/* namep pointer, but one allocation */
/* (struct name4 contiguous with string array) */
/* assuredly portable; but only works for "array" of char */

struct name4 {
	int namelen;
	char *namep;
};

struct name4 *makename4(char *newname)
{
	char *buf = malloc(sizeof(struct name4) +
				strlen(newname) + 1);
	struct name4 *ret = (struct name4 *)buf;
	ret->namelen = strlen(newname);
	ret->namep = buf + sizeof(struct name4);
	strcpy(ret->namep, newname);

	return ret;
}

/* a slightly different approach; different strict conformance arguments */

struct name4 *makename4a(char *newname)
{
	struct name4 *ret = malloc(sizeof(struct name4) +
				strlen(newname) + 1);
	ret->namelen = strlen(newname);
	ret->namep = (char *)ret + sizeof(struct name4);
	strcpy(ret->namep, newname);

	return ret;
}

/* now, arrays of other than char */

#include <stddef.h>

typedef long athing;

struct thing1 {
	int thinglen;
	athing *thingp;
	athing dummy;
};

struct thing1 *makething1(int len, athing *things)
{
	void *buf = malloc(sizeof(struct thing1) +
				(len - 1) * sizeof(athing));
	struct thing1 *ret = (struct thing1 *)buf;
	ret->thinglen = len;
	ret->thingp = (athing *)((char *)buf + offsetof(struct thing1, dummy));
	memcpy(ret->thingp, things, len * sizeof(athing));

	return ret;
}

/*
 *  [msb:]
 *  "But RR2 appears, incredibly, to be ruling *this* nonconforming too
 *  (and without a proper explanation either -- I urged in my review
 *  that one be supplied, since I could make no sense of the ruling).
 *  An alternative is to eliminate the "dummy" member and calculate
 *  the quantity "sizeof (struct name) rounded up if necessary to a
 *  multiple of sizeof(athing)" by hand, instead of using offsetof."
 */

/* [as I attempt below] */

#define Roundup(a, b) ((((a) - 1) / (b) + 1) * (b))

struct thing2 {
	int thinglen;
	athing *thingp;
};

struct thing2 *makething2(int len, athing *things)
{
	void *buf = malloc(Roundup(sizeof(struct thing2), sizeof(athing)) +
				len * sizeof(athing));
	struct thing2 *ret = (struct thing2 *)buf;
	ret->thinglen = len;
	ret->thingp = (athing *)((char *)buf +
			Roundup(sizeof(struct thing2), sizeof(athing)));
	memcpy(ret->thingp, things, len * sizeof(athing));

	return ret;
}

#include <stdio.h>

#ifdef __STDC__
void printp(char *, void *);
#endif
void printp();

main()
{
athing things1[10];
athing things2[20];
struct name1 *n1 = makename1("This");
struct name2 *n2 = makename2("is");
struct name3 *n3 = makename3("a");
struct name4 *n4 = makename4("test.");
struct name4 *n4a = makename4a("program");
struct thing1 *t1 = makething1(10, things1);
struct thing2 *t2 = makething2(20, things2);

printf("n1: %d, \"%s\"\n", n1->namelen, n1->namestr);
printf("n2: %d, \"%s\"\n", n2->namelen, n2->namestr);
printf("n3: %d, \"%s\"\n", n3->namelen, n3->namep);
printf("n4: %d, \"%s\"\n", n4->namelen, n4->namep);
printf("n4a: %d, \"%s\"\n", n4a->namelen, n4a->namep);

printp("n1", (void *)n1);
printp("n2", (void *)n2);
printp("n3", (void *)n3);
printp("n4", (void *)n4);
printp("n4a", (void *)n4a);
printp("t1", (void *)t1);
printp("t2", (void *)t2);

return 0;
}

#ifdef mac
#define mallocsize(p) (-*(int *)((char *)(void *)(p)-2)-3)	/* Think C */
#endif

void
printp(tag, p)
char *tag;
void *p;
{
printf("%s: %p", tag, p);
#ifdef mallocsize
printf(": %d", mallocsize(p));
#endif
printf("\n");
}
