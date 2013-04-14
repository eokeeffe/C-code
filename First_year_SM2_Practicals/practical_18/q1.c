/*Evan O'Keeffe
  10324289
  practical 18 question1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR printf("memory allocation failed\r\n");
char *p;

char * duplicate(char* string)
{
	p=(char* )malloc(sizeof(char*));
	
	if(p!=NULL)
	{
		strcpy(p,string);
		return p;
	}
	else 
		{
			ERROR
		}
}

int main()
{
	char* string;
	printf("please enter a word\r\n");
	gets(string);
	duplicate(string);
	printf("%s is the duplicate\r\n",p);
	return 0;
}