/*
 *  Code for the book
 *  C Programming FAQs: Frequently Asked Questions
 *  Addison-Wesley, 1996, ISBN 0-201-84519-9
 *  (question 20.28)
 *
 *  This code from a message posted to Usenet comp.lang.c:
 *
 *  From: mikey@ontek.com (euphausia superba)
 *  Date: 27 Apr 94 18:53:42 GMT
 *  Message-ID: <2479@ontek.com>
 */

/*
soundex

Copyright 1994 Michael Lee <mikey@ontek.com>
Permission to use for any purpose granted.

Refer to Knuth, Art of Computer Programming Vol. 3, pp 391-392.
*/

#include <stdio.h>
#include <ctype.h>

void soundex(name, sound)
  char   * name;
  char   * sound;  /* supply at least 5 pre-allocated characters */
{
  char   * in = name,
         * out = sound;
  char   prev = '\0';
  int    is_first = 1;
  char   code;

  while (*in != '\0' && out - sound < 4)
  {
    switch(tolower(*in))
    {
      case 'b':
      case 'f':
      case 'p':
      case 'v':
        code = '1';
      break;

      case 'c':
      case 'g':
      case 'j':
      case 'k':
      case 'q':
      case 's':
      case 'x':
      case 'z':
        code = '2';
      break;

      case 'd':
      case 't':
        code = '3';
      break;

      case 'l':
        code = '4';
      break;

      case 'm':
      case 'n':
        code = '5';
      break;

      case 'r':
        code = '6';
      break;

      /* includes "aehiouwy", punctuation, numbers and control chars */
      default:
        code = 0;
      break;
    }

    if (is_first)
    {
      *out++ = toupper(*in);
      is_first = 0;
    }
    else if (code && prev != code)
      *out++ = code;
    prev = code;

    in++;
  }

  while (out - sound < 4)
    *out++ = '0';

  *out = '\0';

}

#ifdef TEST
#include <string.h>
main()
{
  char buffer[100];
  char mangle[10];
  char * nl;

  while(!feof(stdin))
  {
    printf("name: ");
    fgets(buffer, sizeof(buffer), stdin);
    nl = strchr(buffer, '\n');
    if (nl) *nl = '\0';

    soundex(buffer, mangle);
    printf("soundex = %s\n\n", mangle);
  }

  return 0;
}
#endif
