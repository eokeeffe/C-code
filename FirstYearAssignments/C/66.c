/*Evan o'Keeffe
 10324289
 this is my version of the myputstr function*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void mymyputstr(char string[]);
main()
{
	char string[100];
	printf("please enter your string\r\n");
	gets(string);
	mymyputstr(string);
	
}
void mymyputstr(char string[])
{
	int i=0;
	while(string[i]!='\0')
	{
		putchar(string[i]);
		i++;
	}
	printf("your string %s\r\n",string);
	exit(0);
}