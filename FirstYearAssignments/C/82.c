/*Evan o'Keeffe
 10324289
 string compare that takes user parameters from the cmd*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int mystrcmp();
int mystrcmp1(char *argv[],char *argv1[]);
main(int argc,char *argv[],char *argv1[])
{
	/*mystrcmp();*/
	mystrcmp1(argv,argv1);	
	exit(0);
}
int mystrcmp()
{
	char string1[100],string2[100];
	int a,b,c=0,d=0,e=0,i;
	
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
int mystrcmp1(char *argv[],char *argv1[])
{	
	FILE *fopen(),*fp,*fp1;
	
	int a,b,c=0,d,e,i;
	
	fp=fopen(argv[1],"r");
	fp1=fopen(argv1[1],"r");
	
	d=getc(fp);
	e=getc(fp1);
	while(d!=EOF||e!=EOF)
	{
		d=getc(fp);
		e=getc(fp1);
		i++;
	}
	a=(strlen(argv[1]));
	b=(strlen(argv1[1]));
	printf("%d\r\n",a);
	printf("%d\r\n",b);
	if(a>b){c=1;}
	if(a==b){c=0;}
	if(a<b){c=-1;}
	if(c==1){printf("string 1 is bigger\r\n");}
	if(c==0){printf("the same\r\n");}
	else{printf("string 2 is bigger\r\n");}
}