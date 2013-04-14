#include<stdio.h>
#include"calc.h"
/* POP : pop and return top value from the stack*/
extern double pop(void)
{
	if(sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\r\n");
		return 0.0;
	}
}
