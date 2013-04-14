/*Evan o'Keeffe
 10324289
 this is my version of the strlen function*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void mystrlen();
void main()
{	
	mystrlen();
	exit(0);
}

void mystrlen()
{
	FILE *fopen(),*fp;
	int c,i=0;
	char filename[100];
	
	printf("Please enter the file to count\r\n");
	gets(filename);
	fp=fopen(filename,"r");
	
	c=getc(fp);
	while(c!=EOF)
	{	
		c=getc(fp);
		i++;
	}
	fclose(fp);
	printf("your file has %d characters in it\r\n",i);
}