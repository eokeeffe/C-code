 /*Evan o'Keeffe
 10324289
 this is actually a faulty program , i keep it for 51.c and 
 the other ones so i can have an example of bad code
 to illustrate what the program does
 the only problem with it is its missing a '}' at the end */
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main()
{
	FILE *fopen(),*fp;
	int c;
	int cntr1=0,cntr2=0,cntr3=0;
	int cntr4=0,cntr5=0;
	char filename1[50];
	
	printf("Enter file 1 to be read:\r\n");
	gets( filename1 ) ;

	fp=fopen(filename1,"r"); 	/* open for reading */ 
  
	if(fp==NULL)
	{
	printf("Cannot open %s for reading\n",filename1);
	exit(0);
	}
	
	c = getc(fp) ;			
	while (c!=EOF)
	{
	cntr1++;
	if(c=='{'){cntr2++;}
	if(c=='}'){cntr3++;}
	if(c=='('){cntr4++;}
	if(c==')'){cntr5++;}
	c=getc(fp);			
	
	fclose(fp); 
	
	/*printf("the program %s \r\n",filename1);*/
	/*printf("has %d '{' and %d '}'\r\n",cntr2,cntr3);
	  printf("and %d '(' and %d ')'\r\n",cntr4,cntr5);*/
	  
	if(cntr2==cntr3&&cntr4==cntr5)
	{
	printf("Your Program is safe to use\r\n");
	
	
}