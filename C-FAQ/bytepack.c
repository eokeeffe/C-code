/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (questions 12.42 and 16.7)
 *
 *  This code may be used or modified as desired,
 *  without any restriction.
 *
 *  This code takes several instances of a binary structure and
 *  "packs" them into a byte array, then unpacks and compares
 *  them to the original.  Invoked without an argument, it also
 *  writes the structures out to the file DATAFILE.  Invoked
 *  with a filename argument, it reads data form that file and
 *  compares to the original data.
 *
 *  The conversion to and from byte arrays, and the writing to
 *  and reading from data files, is in all cases "binary," but
 *  is done a byte at a time, for portability and control over
 *  word size and byte order.
 *
 *  The comparisons verify that both pairs of functions
 *  (packstruct and unpackstruct, writestruct and readstruct)
 *  preserve the data faithfully.
 */

#include <stdio.h>
#ifdef mac
#include <console.h>
#endif
#include "defs.h"

struct mystruct {
	char c;
	long int i32;
	int i16;
};

#define DATAFILE "bytepack.dat"

int cvalues[] =
	{
	0,
	1,
	'\r',
	'\n',
	'Z' & 037,
	127,
	128,
	129,
	254,
	255,
	256
	};

int ivalues[] =
	{
	0x0000,
	0x0001,
	0x007e,
	0x007f,
	0x0080,
	0x00fe,
	0x00ff,
	0x0a0d,
	0x0d0a,
	0x0100,
	0x0102,
	0x07fe,
	0x07ff,
	0x0800,
	0x0ffe,
	0x0fff,
	0x1000,
	0x7ffe,
	0x7fff,
	0x8000,
	0xff00,
	0xfffe,
	0xffff,
	};

long int lvalues[] =
	{
	0x00000000L,
	0x00000001L,
	0x000000feL,
	0x000000ffL,
	0x00000100L,
	0x0000ff00L,
	0x0000fffeL,
	0x0000ffffL,
	0x0a0d0a0d,
	0x0d0a0d0a,
	0x00010000,
	0x00ff0000,
	0x00fffffe,
	0x00ffffff,
	0x01000000,
	0x01020304,
	0xff000000,
	0xfffffffe,
	0xffffffff,
	};

#define Sizeofarray(a) (sizeof(a) / sizeof(a[0]))

#ifdef __STDC__
void writestruct(struct mystruct *, FILE *);
void readstruct(struct mystruct *, FILE *);
void packstruct(struct mystruct *, unsigned char *);
void unpackstruct(unsigned char *, struct mystruct *);
#endif

void writestruct();
void readstruct();
void packstruct();
void unpackstruct();

main(argc, argv)
int argc;
char *argv[];
{
struct mystruct s, s2;
int i, j, k;
int ii;
FILE *fp;
unsigned char buf[20];
int internal = TRUE;
int writefile = TRUE;
int readfile = TRUE;
char *filename = DATAFILE;

#ifdef mac
argc = ccommand(&argv);
#endif

if(argc > 1)
	{
	filename = argv[1];
	internal = writefile = FALSE;
	}

if(internal)
	{
	for(ii = 0; ii < Sizeofarray(cvalues) + Sizeofarray(ivalues) + Sizeofarray(lvalues); ii++)
		{
		i = j = k = 0;
		if(ii < Sizeofarray(cvalues))
			i = ii;
		else if(ii < Sizeofarray(cvalues) + Sizeofarray(ivalues))
			j = ii - Sizeofarray(cvalues);
		else	k = ii - Sizeofarray(cvalues) - Sizeofarray(ivalues);

		s.c = cvalues[i];
		s.i16 = ivalues[j];
		s.i32 = lvalues[k];

		packstruct(&s, buf);
		unpackstruct(buf, &s2);
		if(s.c != s2.c || s.i16 != s2.i16 || s.i32 != s2.i32)
			{
			printf("%d,%d,%d: %d, %d (%x), %ld (%lx) ",
				i, j, k, s.c, s.i16, s.i16, s.i32, s.i32);
			printf("unpacked as %d, %d (%x), %ld (%lx)\n",
				s2.c, s2.i16, s2.i16, s2.i32, s2.i32);
			}
		}
	}

if(writefile)
	{
	if((fp = fopen(filename, "wb")) == NULL)
		{
		fprintf(stderr, "can't open %s\n", filename);
		exit(1);
		}

	for(ii = 0; ii < Sizeofarray(cvalues) + Sizeofarray(ivalues) + Sizeofarray(lvalues); ii++)
		{
		i = j = k = 0;
		if(ii < Sizeofarray(cvalues))
			i = ii;
		else if(ii < Sizeofarray(cvalues) + Sizeofarray(ivalues))
			j = ii - Sizeofarray(cvalues);
		else	k = ii - Sizeofarray(cvalues) - Sizeofarray(ivalues);

		s.c = cvalues[i];
		s.i16 = ivalues[j];
		s.i32 = lvalues[k];

		writestruct(&s, fp);
		}

	fclose(fp);
	}

if(readfile)
	{
	if((fp = fopen(filename, "rb")) == NULL)
		{
		fprintf(stderr, "can't open %s\n", filename);
		exit(1);
		}

	for(ii = 0; ii < Sizeofarray(cvalues) + Sizeofarray(ivalues) + Sizeofarray(lvalues); ii++)
		{
		i = j = k = 0;
		if(ii < Sizeofarray(cvalues))
			i = ii;
		else if(ii < Sizeofarray(cvalues) + Sizeofarray(ivalues))
			j = ii - Sizeofarray(cvalues);
		else	k = ii - Sizeofarray(cvalues) - Sizeofarray(ivalues);

		s.c = cvalues[i];
		s.i16 = ivalues[j];
		s.i32 = lvalues[k];

		readstruct(&s2, fp);
		if(s.c != s2.c || s.i16 != s2.i16 || s.i32 != s2.i32)
			{
			printf("%d,%d,%d: %d, %d (%x), %ld (%lx) ",
				i, j, k, s.c, s.i16, s.i16, s.i32, s.i32);
			printf("read as %d, %d (%x), %ld (%lx)\n",
				s2.c, s2.i16, s2.i16, s2.i32, s2.i32);
			}
		}

	fclose(fp);
	}

printf("done\n");

return 0;
}

void writestruct(sp, fp)
struct mystruct *sp;
FILE *fp;
{
struct mystruct s;
	s = *sp;	/* just so printed code can use s. */

	putc(s.c, fp);

	putc((unsigned)((s.i32 >> 24) & 0xff), fp);
	putc((unsigned)((s.i32 >> 16) & 0xff), fp);
	putc((unsigned)((s.i32 >> 8) & 0xff), fp);
	putc((unsigned)(s.i32 & 0xff), fp);


	putc((s.i16 >> 8) & 0xff, fp);
	putc(s.i16 & 0xff, fp);
}

#ifdef prettier

void readstruct(sp, fp)
struct mystruct *sp;
FILE *fp;
{
struct mystruct s;

	s.c = getc(fp);

	s.i32 = getc(fp);
	s.i32 = (s.i32 << 8) | getc(fp);
	s.i32 = (s.i32 << 8) | getc(fp);
	s.i32 = (s.i32 << 8) | getc(fp);

	s.i16 = getc(fp);
	s.i16 = (s.i16 << 8) | getc(fp);

	*sp = s;
}

#else

void readstruct(sp, fp)
struct mystruct *sp;
FILE *fp;
{
struct mystruct s;

	s.c = getc(fp);

	s.i32 = (long)getc(fp) << 24;
	s.i32 |= (long)getc(fp) << 16;
#ifdef buggy
	s.i32 |= getc(fp) << 8;
#else
	s.i32 |= (unsigned)(getc(fp) << 8);
#endif
	s.i32 |= getc(fp);

	s.i16 = getc(fp) << 8;
	s.i16 |= getc(fp);

	*sp = s;
}

#endif

void packstruct(sp, buf)
struct mystruct *sp;
unsigned char *buf;
{
	struct mystruct s;
	unsigned char *p = buf;
	s = *sp;	/* just so printed code can use s. */

	*p++ = s.c;

	*p++ = (s.i32 >> 24) & 0xff;
	*p++ = (s.i32 >> 16) & 0xff;
	*p++ = (s.i32 >> 8) & 0xff;
	*p++ = s.i32 & 0xff;

	*p++ = (s.i16 >> 8) & 0xff;
	*p++ = s.i16 & 0xff;
}

#ifdef prettier

void unpackstruct(buf, sp)
unsigned char *buf;
struct mystruct *sp;
{
struct mystruct s;

	unsigned char *p = buf;

	s.c = *p++;

	s.i32 = *p++;
	s.i32 = (s.i32 << 8) | *p++;
	s.i32 = (s.i32 << 8) | *p++;
	s.i32 = (s.i32 << 8) | *p++;

	s.i16 = *p++;
	s.i16 = (s.i16 << 8) | *p++;

	*sp = s;
}

#else

void unpackstruct(buf, sp)
unsigned char *buf;
struct mystruct *sp;
{
struct mystruct s;

	unsigned char *p = buf;

	s.c = *p++;

	s.i32 = (long)*p++ << 24;
	s.i32 |= (long)*p++ << 16;
#ifdef buggy
	s.i32 |= *p++ << 8;
#else
	s.i32 |= (unsigned)(*p++ << 8);
#endif
	s.i32 |= *p++;

	s.i16 = *p++ << 8;
	s.i16 |= *p++;

	*sp = s;
}

#endif
