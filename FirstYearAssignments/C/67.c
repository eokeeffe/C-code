/*Evan o'Keeffe
 10324289
 this is my version of the strcmp function*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int mystrcmp();
int mystrcmp1();
main()
{
	mystrcmp();	
	exit(0);
}
int mystrcmp()
{
	char string1[100],string2[100];
	int a,b,c=0,d=0,e=0;
	
	string1[100]='\0';
	string2[100]='\0';
	
	printf("please enter the first string\r\n");
	gets(string1);
	printf("please enter the second string\r\n");
	gets(string2);
	a=(strlen(string1));
	b=(strlen(string2));
	printf("%d\r\n",a);
	printf("%d\r\n",b);
	if(a>b){c=1;}
	if(a==b){c=0;}
	if(a<b){c=-1;}
	if(c==1){printf("string 1 is bigger\r\n");}
	if(c==0){printf("the same\r\n");}
	else{printf("string 2 is bigger\r\n");}
	return (c);
}
int mystrcmp1()
{	
	FILE *fopen(),*fp,*fp1;
	char string1[100],string2[100];
	int a,b,c=0,d,e;
	
	string1[100]='\0';
	string2[100]='\0';
	
	printf("please enter the file\r\n");
	gets(string1);
	printf("please enter the second file\r\n");
	gets(string2);
	fp=fopen(string1,"r");
	fp1=fopen(string2,"r");
	
	d=getc(fp);
	e=getc(fp1);
	while(d!=EOF||e!=EOF)
	{
		d=getc(fp);
		e=getc(fp1);
		i++;
	}
	a=(strlen(string1));
	b=(strlen(string2));
	printf("%d\r\n",a);
	printf("%d\r\n",b);
	if(a>b){c=1;}
	if(a==b){c=0;}
	if(a<b){c=-1;}
	if(c==1){printf("string 1 is bigger\r\n");}
	if(c==0){printf("the same\r\n");}
	else{printf("string 2 is bigger\r\n");}
}