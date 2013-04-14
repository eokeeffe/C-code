/*Evan o'Keeffe
 10324289
 asks for user input to write something to a file from another file*/
 /*generally I use rewrite1.c for the file to be changed in this program*/
 #include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

main()
{
	FILE *fopen(),*fp,*fp2;
	char fname[100],fname2[100];
	int c;
	
	printf("please enter file to read\r\n");
	gets(fname);
	
	printf("please enter file to write to \r\n");
	gets(fname2);
	
	fp=fopen(fname,"r");
	fp2=fopen(fname2,"w");
	
	if(fp==NULL){printf("there is no file called %s \r\n",fname);}
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
	return 0;
}