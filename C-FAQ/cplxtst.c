/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 14.11)
 */

#include <stdio.h>
#include "complex.h"

main()
{
	complex a = cpx_make(1, 2);
	complex b = cpx_make(3, 4);
	complex c = cpx_add(a, b);

	printf("a: %s\n", cpx_print("%g", a));
	printf("b: %s\n", cpx_print("%g", b));

	printf("c=a+b: %s\n", cpx_print("%g", c));
	c = cpx_subtract(a, b);
	printf("c=a-b: %s\n", cpx_print("%g", c));
	c = cpx_multiply(a, b);
	printf("c=a*b: %s\n", cpx_print("%g", c));
	printf("a+b: %s\n", cpx_print("%g", cpx_add(a, b)));
	printf("1+2i - 3+4i: %s\n", cpx_print("%g",
		cpx_subtract(cpx_make(1, 2), cpx_make(3, 4))));
	{
	complex c = cpx_add(cpx_make(1, 2), cpx_make(3, 4));
	printf("c=1+2i + 3+4i: %s\n", cpx_print("%g", c));
	}
	c = cpx_multiply(cpx_make(1, 2), cpx_make(3, 4));
	printf("c=1+2i * 3+4i: %s\n", cpx_print("%g", c));
	return 0;
}
