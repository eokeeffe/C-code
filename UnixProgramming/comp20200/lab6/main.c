#include <stdio.h>
#include <stdlib.h> /* for atof() */
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

/* reverse Polish calculator */
int main()
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF) 
	{
		switch (type)
		{
			case NUMBER:
			{
				push(atof(s));
				break;
			}
			case '+':
			{
				push(pop() + pop());
				break;
			}
			case '*':
			{
				push(pop() * pop());
				break;
			}
			case '-':
			{
				op2 = pop();
				// push(pop()-pop())is wrong
				push(pop() - op2);
				// since - and / not commutative
				break;
			}
			case '/':
			{
				op2 = pop();
				if (op2 != 0.0)
				{
					push(pop() / op2);
				}
				else
				{
					printf("error: zero divisor\n");
				}
				break;
			}
			case '\n':
			{
				printf("\t %.8g \n", pop());
				break;
			}
			default:
			{
				printf("error: unknown command %s\n", s);
				break;
			}
		}
	}
	return 0;
}
