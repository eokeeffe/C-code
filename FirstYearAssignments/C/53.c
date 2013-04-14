 /*Evan o'Keeffe
 10324289
 counts words in the file asked for*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define YES 1
#define NO 0
main()
{
	FILE *fopen(),*fp;
	int c,nl,nw,inword;
	double nc;
	char filename1[50];
	inword=NO;
	nl=nw=nc=0;
	
	printf("Enter file 1 to be read:\r\n");
	gets( filename1 ) ;

	fp=fopen(filename1,"r"); 	/* open for reading */ 
  
	if(fp==NULL)
	{
	printf("Cannot open %s for reading\n",filename1);
	exit(0);
	}
	
	while((c = getc(fp)) !=EOF)
	{	
	++nc;
	if(c=='\n')
	{++nl;}
	if(c==' '||c=='\n'||c=='\t')
	{inword=NO;}
	else if(inword==NO)
	{inword==YES; ++nw;}
	}
	printf("%d %d %d\n",nl,nw,nc);
}
		
	
