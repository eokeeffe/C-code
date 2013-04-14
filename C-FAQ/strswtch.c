/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 20.17)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdio.h>

#define CODE_APPLE	1
#define CODE_ORANGE	2
#define CODE_NONE	0

#ifdef __STDC__
int classifyfunc(char *);
#endif

main()
{
	char *string = "apple";

	switch(classifyfunc(string)) {
	case CODE_APPLE:
		printf("apple\n");
		break;

	case CODE_ORANGE:
		printf("orange\n");
		break;

	case CODE_NONE:
		printf("other\n");
		break;
	}

	return 0;
}

static struct lookuptab {
	char *string;
	int code;
} tab[] = {
	{"apple",	CODE_APPLE},
	{"orange",	CODE_ORANGE},
};

classifyfunc(char *string)
{
	int i;
	for(i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
		if(strcmp(tab[i].string, string) == 0)
			return tab[i].code;

	return CODE_NONE;
}
