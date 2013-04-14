/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 13.6)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 *
 *  Test code demonstrating the use of strtok and makeargv to
 *  split strings into whitespace-separated words, as well as
 *  simple techniques using strchr, strspn, strpbrk to do similar
 *  splitting "by hand."
 */

#include <stdio.h>
#include <string.h>
#ifdef mac
#include <console.h>
#endif

#ifdef __STDC__
extern int makeargv(char *, char *[], int);
#endif

main(argc, argv)
int argc;
char *argv[];
{
#ifdef publish
	char string[] = "this is a test";	/* not char *; see Q <xref target=nstringlitnotmodif> */
#else
	char string[100];
#endif
	char *p;

	char stringcopy[100];
	int l;

#ifdef mac
	console_options.nrows = 40;
     /*	argc = ccommand(&argv); */
#endif

	while(fgets(string, sizeof(string), stdin) != NULL)
	{
	printf("strtok:\n");

	strcpy(stringcopy, string);

	for(p = strtok(stringcopy, " \t\n"); p != NULL;
				p = strtok(NULL, " \t\n"))
		printf("\"%s\"\n", p);

	printf("makeargv:\n");

	strcpy(stringcopy, string);

	{
#ifdef publish
	char *av[10];
#else
	char *av[10+1];
#endif
	char dummy;
	av[10] = &dummy;
	{
	int i, ac = makeargv(stringcopy, av, 10);

	printf("(%d)\n", ac);
	for(i = 0; i < ac; i++)
		printf("\"%s\"\n", av[i]);
	if(ac < 10)
		printf("%p\n", av[ac]);
	if(av[10] != &dummy)
		printf("OOPS: av overflowed\n");
	}
	}

	l = strlen(string);
	if(string[l-1] == '\n')
		string[l-1] = '\0';

	printf("strchr loop:\n");

	strcpy(stringcopy, string);

	{

char *p = stringcopy;

while(1) {		/* break in middle */
	char *p2 = strchr(p, '\t');
	if(p2 != NULL)
		*p2 = '\0';
	printf("\"%s\"\n", p);
	if(p2 == NULL)
		break;
	p = p2 + 1;
}
	}

	printf("strpbrk loop:\n");

	strcpy(stringcopy, string);

	{
char *p = stringcopy;

/* doesn't deal with multiple (or only) whitespace well */

while(1) {	/* break in middle */
	char *p2 = strpbrk(p, " \t\n");
	if(p2 != NULL)
		*p2 = '\0';
	printf("\"%s\"\n", p);
	if(p2 == NULL)
	break;
	p = p2 + 1;
}
	}

	printf("strspn + strpbrk loop:\n");

	strcpy(stringcopy, string);

	{
char *p = stringcopy;

/* doesn't deal with trailing (or only) whitespace well */

while(1) {	/* break in middle */
	char *p2;
	p += strspn(p, " \t\n");
	p2 = strpbrk(p, " \t\n");
	if(p2 != NULL)
		*p2 = '\0';
	printf("\"%s\"\n", p);
	if(p2 == NULL)
		break;
	p = p2 + 1;
}
	}
	}

	return 0;
}
