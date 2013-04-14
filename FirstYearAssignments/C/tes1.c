/*proof of concept*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
main()
{
	FILE *fopen(),*fp;
	char fname[200],a[1000];
	int c=0,i=0,j=0,d=0;
	
	while(j++!=1000){a[j]='\0';}
	
	printf("please enter the name of the file to encrpyt\r\n");
	gets(fname);
	fp=fopen(fname,"r");
	
	if(fp==NULL){printf("this file doesn't exist\r\n");}
	
	c=getc(fp);
	while(c!=EOF)
	{
		c=getc(fp);
		a[i]=c;
		i++;
	}
	printf("the lenght of the file is %d\r\n",i);
	fgets(a,999,fp);
	printf("a=%s\r\n",a);
	d=strlen(a);
	printf("the lenght of a=%d\r\n",d);
	
}