/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 20.3)
 *
 *  This code may be used or modified as desired,
 *  without restriction.
 *
 *  (There are two complete versions here: the first parses
 *  argv by hand; the second calls getopt.)
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>


#ifdef mac
#include <console.h>
#endif

#define GETOPT

#ifndef GETOPT

main(int argc, char *argv[])
{
	int argi;
	int aflag = 0;
	char *bval = NULL;
#ifdef mac
	argc = ccommand(&argv);
#endif

	for(argi = 1; argi < argc && argv[argi][0] == '-'; argi++) {
		char *p;
		for(p = &argv[argi][1]; *p != '\0'; p++) {
			switch(*p) {
			case 'a':
				aflag = 1;
				printf("-a seen\n");
				break;

			case 'b':
				bval = argv[++argi];
				printf("-b seen (\"%s\")\n", bval);
				break;

			default:
				fprintf(stderr,
					"unknown option -%c\n", *p);
			}
		}
	}

	if(argi >= argc) {
		/* no filename arguments; process stdin */
		printf("processing standard input\n");
	} else {
		/* process filename arguments */

		for(; argi < argc; argi++) {
			FILE *ifp = fopen(argv[argi], "r");
			if(ifp == NULL) {
				fprintf(stderr, "can't open %s: %s\n",
					argv[argi], strerror(errno));
				continue;
			}

			printf("processing %s\n", argv[argi]);

			fclose(ifp);
		}
	}

	return 0;
}

#else

#ifdef __STDC__
extern int getopt(int, char * const *, const char *);
#endif

extern char *optarg;
extern int optind;

main(int argc, char *argv[])
{
	int aflag = 0;
	char *bval = NULL;
	int c;
#ifdef mac
	argc = ccommand(&argv);
#endif

	while((c = getopt(argc, argv, "ab:")) != -1)
		switch(c) {
		case 'a':
			aflag = 1;
			printf("-a seen\n");
			break;

		case 'b':
			bval = optarg;
			printf("-b seen (\"%s\")\n", bval);
			break;
	}

	if(optind >= argc) {
		/* no filename arguments; process stdin */
		printf("processing standard input\n");
	} else {
		/* process filename arguments */

		for(; optind < argc; optind++) {
			FILE *ifp = fopen(argv[optind], "r");
			if(ifp == NULL) {
				fprintf(stderr, "can't open %s: %s\n",
					argv[optind], strerror(errno));
				continue;
			}

			printf("processing %s\n", argv[optind]);

			fclose(ifp);
		}
	}

	return 0;
}

#endif
