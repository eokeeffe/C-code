/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 20.6)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

int func(), anotherfunc();

struct { char *name; int (*funcptr)(); } symtab[] = {
	"func",		func,
	"anotherfunc",	anotherfunc,
};

#include <stddef.h>

int (*findfunc(char *name))()
{
	int i;

	for(i = 0; i < sizeof(symtab) / sizeof(symtab[0]); i++) {
		if(strcmp(name, symtab[i].name) == 0)
			return symtab[i].funcptr;
		}

	return NULL;
}

#include <stdio.h>

main()
{
	char *funcname = "func";
	int (*funcp)() = findfunc(funcname);
	if(funcp != NULL)
		(*funcp)();
	funcname = "func2";
	funcp = findfunc(funcname);
	if(funcp != NULL)
		(*funcp)();
	funcname = "anotherfunc";
	funcp = findfunc(funcname);
	if(funcp != NULL)
		(*funcp)();
	return 0;
}

func()
{
	printf("this is func\n");
	return 0;
}

anotherfunc()
{
	printf("this is anotherfunc\n");
	return 0;
}
