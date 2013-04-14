 /*Evan o'Keeffe
 10324289
 learning how to use toupper and tolower and toascii*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{

  char str[80];
  int i;

  printf("Enter a string: \r\n");
  gets(str);

  for( i = 0; str[ i ]; i++)
    str[ i ] = toupper( str[ i ] );

  printf("%s\n", str); /* uppercase string */

  for(i = 0; str[ i ]; i++)
    str[i] = tolower(str[ i ]);

  printf("%s\n", str); /* lowercase string */
  
  for(i = 0;str[i];i++)
	str[i] = toascii(str[i]);/*produces a sum of ascii characters*/

  printf("%d\n",str);

  return 0;
}

	