/*
 *  Code from the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 13.6)
 *
 *  Copyright Steve Summit, 1995
 *  This code may be used or modified as desired;
 *  an acknowledgement would be appreciated.
 *  No warranty or representation is offered,
 *  nor is any liability accepted.
 *
 *  makeargv breaks a string up into whitespace-separated "words" or
 *  tokens, and fills in argv[] with pointers to the successive words.
 *  It therefore performs an analogous function to that which the C
 *  run-time startup code (or a shell) presumably performs when
 *  constructing the argv array with which main() is invoked.
 *
 *  The definition of the "whitespace" that separates words
 *  is determined by the isspace() macro from <ctype.h>.
 *  No quoting (\, ', or ") is honored.
 *
 *  \0 characters are inserted into the original string to delineate
 *  each word.  Therefore, the input string must be writable, and if
 *  the caller will later require access to the unmodified string,
 *  the caller is responsible for making a copy.
 *
 *  string points to the string which is to be broken up.
 *  argv is the array of char * pointers to be filled in;
 *  argvsize is its size (the maximum number of pointers it
 *  can contain).  The number of words found, i.e. the number
 *  of pointers filled in, i.e. argc, is returned.
 *
 *  If there are more words in the input string than there are slots
 *  available in argv (as determined by argvsize), the last cell in
 *  argv, argv[argvsize-1], will end up pointing to the terminal part
 *  of the string, still containing whitespace.  (For example, if
 *  argvsize is 3, the string "a b c d e" will be split up into the
 *  arguments "a", "b", and "c d e".)  If there are fewer words in the
 *  input string than there are slots available in argv, the ulultimate
 *  cell in argv, argv[argc], is filled in with a null pointer.
 */

#include <ctype.h>

int makeargv(char *string, char *argv[], int argvsize)
{
	char *p = string;
	int  i;
	int argc = 0;

	for(i = 0; i < argvsize; i++) {
		/* skip leading whitespace */
		while(isspace(*p))
			p++;

		if(*p != '\0')
			argv[argc++] = p;
		else {
			argv[argc] = 0;
			break;
		}

		/* scan over arg */
		while(*p != '\0' && !isspace(*p))
			p++;
		/* terminate arg: */
		if(*p != '\0' && i < argvsize-1)
			*p++ = '\0';
	}

	return argc;
}
