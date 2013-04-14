 /*Evan o'Keeffe
 10324289
 this program asks for the program to output*/
 /*other version*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

main()
{
	FILE *fopen(),*fp;
	int c;
	int counter1=0,counter2=0;
	char filename[50];
	
	printf("Enter file to be displayed:\r\n");
	gets( filename ) ;

	fp=fopen(filename,"r"); 	/* open for reading */ 
  
	if(fp==NULL)
	{
	printf("Cannot open %s for reading\n",filename);
	exit(0);
	}
	c = getc( fp ) ;			/* file could be empty */
	while (  c != EOF )
	{
	putchar(c);					
	c = getc ( fp );			/* get next char from file */
	}
	fclose( fp ); 
}
