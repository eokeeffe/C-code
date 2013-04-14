/*
 * reads from fi until newline or EOF.  Puts at most max characters (but never
 * the newline) into string and appends \0.  Returns number of characters in
 * string, exclusive of \0.  (i.e. returns 0 for blank line terminated by
 * newline.)  Reads properly a string terminated with an EOF, but returns EOF
 * on a blank line with no newline, terminated with an EOF.
 */

#include <stdio.h>

getline(fi, string, max)
FILE *fi;
char string[];
register int max;
{
register int i;
register int c;
max--;		/* leave room for '\0' */
i = 0;
while((c = getc(fi)) != EOF && c != '\n') if(i < max) string[i++] = c;
string[i] = '\0';
return(c == EOF && i == 0 ? EOF : i);
}
