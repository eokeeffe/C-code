 /*Evan o'Keeffe
 10324289
 counts the number of characters in a program*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main()
{
	FILE *fopen(),*fp;
	int c ;
	int counter;
	counter=0;
	
	fp = fopen( "39.c", "r" ); /* open for reading */
	c = getc(fp);			   /* file could be empty */
	if ( fp == NULL)
	{
	printf("Cannot open 39.c for reading \r\n");
	exit(0) ; 				   /* Terminate program! */
	}
	while (c!=EOF)
	{
	putchar( c ); 		/*display c on screen */
	counter++;
	c = getc ( fp ); 	/*get next char from file */
	}
	fclose( fp );
	printf("there are %d\r\n",counter);
}