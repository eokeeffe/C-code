/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 1.22)
 *
 *  Cunning version involving recursive structures,
 *  as suggested by Paul Eggert, Eugene Ressler, Chris Volpe,
 *  and probably others.
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

struct functhunk {
	struct functhunk (*func)();
};

struct functhunk start(), stop();
struct functhunk state1(), state2(), state3();

void statemachine()
{
	struct functhunk state = {start};

	while(state.func != stop)
#ifdef oldway
		state = (*state.func)();
#else
		state = state.func();
#endif
}

static int count;


struct functhunk start()
{
	struct functhunk ret;
	count = 0;
	ret.func = state1;
	return ret;
}

struct functhunk state1()
{
struct functhunk ret;
printf("This is state 1\n");
ret.func = state2;
return ret;
}

struct functhunk state2()
{
struct functhunk ret;
printf("This is state 2\n");
ret.func = state3;
return ret;
}

struct functhunk state3()
{
struct functhunk ret;
count++;
printf("This is state 3\n");
ret.func = (count < 3) ? state1 : stop;
return ret;
}

struct functhunk stop()
{
printf("can't happen\n");
exit(1);
}
