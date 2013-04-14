/* test program for agetline() (see agetline.c) */
/* Steve Summit 4/1995 */

#include <stdio.h>
#include <stdlib.h>

#ifdef __STDC__
extern char *agetline(FILE *);
#endif
extern char *agetline();

main()
{
char *p;

do	{
	p = agetline(stdin);

	if(p != NULL)
		printf("agetline returned \"%s\"\n", p);
	else	printf("agetline returned NULL\n");

	free(p);
	} while(p != NULL);

return 0;
}
