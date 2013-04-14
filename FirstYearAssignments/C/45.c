 /*Evan o'Keeffe
 10324289
 counts the number of lines in a program*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main()
{
	FILE *fopen(),*fp;
	int c;
	int counter;
	counter=0;
	
	fp = fopen( "32.c", "r" ); /* open for reading */
	c = getc(fp);			  
	if (fp==NULL)		   /* file could be empty */
	{
	printf("Cannot open 32.c for reading \r\n");
	exit(0) ; 				   /* Terminate program! */
	}
	while(c!=EOF)
	{
	c=getc(fp);
	if(c=='\n')
	{	counter++;}
	}
	fclose( fp );
	printf("there are %d\r\n",counter);
}