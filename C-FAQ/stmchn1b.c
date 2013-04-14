/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 1.22)
 *
 *  "Conventional" version involving function pointer casts
 *  (state variable is pointer to function)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdio.h>

#ifdef __STDC__
void statemachine(void);
#endif
void statemachine();

main()
{
statemachine();
return 0;
}

typedef int (*funcptr)();	/* generic function pointer */

funcptr start(), stop();
funcptr state1(), state2(), state3();

void statemachine()
{
	funcptr state = (funcptr)start;

	while(state != (funcptr)stop)
#ifdef oldway
		state = (*(funcptr (*)())state)();	/* black magic */
#else
		state = ((funcptr (*)())state)();	/* black magic */
#endif
}

static int count;

funcptr start()
{
	count = 0;
	return (funcptr)state1;
}

funcptr state1()
{
	printf("This is state 1\n");
	return (funcptr)state2;
}

funcptr state2()
{
	printf("This is state 2\n");
	return (funcptr)state3;
}

funcptr state3()
{
	count++;
	printf("This is state 3\n");
	return (count < 3) ? (funcptr)state1 : (funcptr)stop;
}

funcptr stop()
{
	printf("can't happen\n");
	exit(1);
}
