/*Evan o'Keeffe
 10324289
 this is my version of the getstr function*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void getstr(char string[]);
main()
{
	char string[100];
	
	printf("please enter your string\r\n");
	getstr(string);
	printf("you have entered %s \r\n",string);
	exit(0);
}
void getstr(char string[])
{
	int i=0;
	string[i]=getchar();
	while(string[i]!='\n')
	{
	i++;
	string[i]=getchar();
	}
	string[i]='\0';
}