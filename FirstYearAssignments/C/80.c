/*Evan o'Keeffe
 10324289
 My Filecopy function 2.0*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void myfilecopy(int argc,char *argv[]);
main(int argc,char *argv[])
{
	myfilecopy(argc,argv);
	exit(0);
}
void myfilecopy(int argc,char *argv[])
{
	FILE *fopen(),*fp,*fp2;
	char choice[100];
	int c;
	
	/*printf("please enter the new file name you wish to copy to\r\n");
	gets(choice);*/
	fp=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	
	if(fp==NULL){printf("there is no file called %s \r\n",argv[1]);}
	
	else 
	{
		c=getc(fp);
		while(c!=EOF)
		{
			c=getc(fp);
			putc(c,fp2);
		}
		fclose(fp);
		fclose(fp2);
	}
	if(fp==NULL||fp2==NULL){printf("there has been an error\r\n");}
	else{printf("the copy was succesful from %s to %s\r\n",argv[1],argv[2]);}
}