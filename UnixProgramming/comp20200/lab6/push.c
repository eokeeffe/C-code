#include<stdio.h>
#include "calc.h"
/* value stack */
/* push: push f onto value stack */
extern void push(double f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, can't push %g\n", f);
	}
}
