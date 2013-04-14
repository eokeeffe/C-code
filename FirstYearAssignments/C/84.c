/*Evan O'Keeffe
  10324289
  reversing a string*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char reverse(char string[]);
char string[200];
char string2[200];
main()
{
	printf("please enter your string\r\n");
	gets(string);
	reverse(string);
	printf("your string has been reversed from %s\r\n",string);
	printf("to %s \r\n",string2);
}
char reverse(char string[])
{	
	int i;
	i=strlen(string)-1;
	while(i>=0)
	{
		putchar(string[i]);
		i=i-1;
	}
	putchar('\n');

}