 /*Evan o'Keeffe
 10324289
 counts the number of brackets*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

main()
{
	FILE *fopen(),*fp;
	int c;
	int counter1,counter2;
	counter1=0;
	counter2=0;
	
	
	fp = fopen( "39.c", "r" ); /* open for reading */
	c = getc(fp);			   /* file could be empty */
	if ( fp == NULL)
	{
	printf("Cannot open 39.c for reading \r\n");
	exit(0); 				   /* Terminate program! */
	}
	while (c!=EOF)
	{
	c=getc(fp); 	/*get next char from file */
	if(c=='('){counter1++;}
	if(c==')'){counter2++;}
	}
	fclose(fp);
	printf("there are %d '(' and %d ')'\r\n",counter1,counter2);
}