/*Evan o'Keeffe
 10324289
 this is my version of the filecopy function*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
void myfilecopy(char *argv[],char *argv1[]);
main(int argc,char *argv[],char *argv1[])
{
	myfilecopy(argv,argv1);
	exit(0);
}
void myfilecopy(char *argv[],char *argv1[])
{
	FILE *fopen(),*fp,*fp2;
	int c;
	
	fp=fopen(argv[1],"r");
	fp2=fopen(argv1[1],"w");
	
	if(fp==NULL){printf("there is no file called %s \r\n",fp);}
	else if(fp2==NULL){printf("you didn't input any filename \r\n");}
	
	else 
	{
		c=getc(fp);
		while(c!=EOF)
		{
			putc(c,fp2);
			c=getc(fp);
		}
		fclose(fp);
		fclose(fp2);
	}
	if(fp==NULL||fp2==NULL){printf("there has been an error\r\n");}
	else{printf("the copy was succesful from %s to %s\r\n",fp,fp2);}
}