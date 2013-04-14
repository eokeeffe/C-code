/* test program for vstrcat() (see vstrcat.c) */
/* Steve Summit 7/1995 */

#include <stdio.h>
#include <stdlib.h>

#ifdef __STDC__
extern char *vstrcat(char *, ...);
#else
extern char *vstrcat();
#endif

main()
{
	char *str = vstrcat("Hello, ", "world!", (char *)NULL);
	printf("%s\n", str);
	free(str);

	str = vstrcat("test", (char *)NULL);
	printf("%s\n", str);
	free(str);

	str = vstrcat("super", "cala", "fragi", "listic",
		"expi", "ali", "docious", (char *)NULL);
	printf("%s\n", str);
	free(str);

	str = vstrcat((char *)NULL);
	printf("\"%s\"\n", str);
	free(str);

	return 0;
}
