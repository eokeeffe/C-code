/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 19.20)
 *
 *  Requires Posix-style opendir(), readdir(), etc. functions;
 *  see text for other comments.
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 */

#include <stdio.h>
#ifdef mac
#include "dirent.h"
#else
#include <sys/types.h>
#include <dirent.h>
#endif

main()
{
	struct dirent *dp;
	DIR *dfd = opendir(".");
	if(dfd != NULL) {
		while((dp = readdir(dfd)) != NULL)
			printf("%s\n", dp->d_name);
		closedir(dfd);
	}
	return 0;
}
