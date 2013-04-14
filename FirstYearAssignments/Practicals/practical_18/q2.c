/*Evan O'Keeffe
  10324289
  practical 18 question2
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR printf("memory allocation failed\r\n");
char *p;

char * duplicate(char* string1,char* string2)
{
	p=(char* )malloc(sizeof(char*)*strlen(string1)*strlen(string2));
	
	if(p!=NULL)
	{
		p = strcat(string1,string2);
		return p;
	}
	else 
		{
			ERROR
		}
}

int main()
{
	char string1[100];
	char string2[100];

	printf("please enter a word\r\n");
	gets(string1);
	printf("please enter another word\r\n");
	gets(string2);
	duplicate(string1,string2);
	
	printf("%s is the concatenation\r\n",p);
	return 0;
}