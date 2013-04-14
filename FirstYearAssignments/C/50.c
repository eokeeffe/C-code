 /*Evan o'Keeffe
 10324289
 this program compares if two programs are identical or not*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

main()
{
	FILE *fopen(),*fp,*fp2;
	int c,d;
	int counter1=0,counter2=0;
	char filename1[50],filename2[50];
	
	printf("Enter file 1 to be read:\r\n");
	gets( filename1 ) ;
	printf("Enter file 2 to be read:\r\n");
	gets( filename2 ) ;
	

	fp=fopen(filename1,"r"); 	/* open for reading */ 
  
	if(fp==NULL)
	{
	printf("Cannot open %s for reading\n",filename1);
	exit(0);
	}
	c = getc( fp ) ;			/* file could be empty */
	while (  c != EOF )
	{
	counter1++;				 
	c = getc ( fp );			/* get next char from file */
	}
	fclose( fp ); 
	
	fp2=fopen(filename2,"r"); 	/* open for reading */ 
	if(fp2==NULL)
	{
	printf("Cannot open %s for reading\n",filename2);
	exit(0);
	}
	d = getc( fp2 ) ;			/* file could be empty */
	while (  d != EOF )
	{
	counter2++;				 
	d = getc ( fp2 );			/* get next char from file */
	}
	fclose( fp2 ); 
	
	if(counter1==counter2){printf("the files are identical\r\n");}
	else{printf("the files aren't identical\r\n");}
}
