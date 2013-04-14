 /*Evan o'Keeffe
 10324289
 this program takes two program files and reads them and tells you if
 they are the same*/
 /*my version*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

main()
{
	FILE *fopen(),*fp1,*fp2;
	int c,d;
	int counter1,counter2;
	
	if (fp1==NULL||fp2==NULL)
	{
	printf("Cannot open 39.c or 40.c for comparison \r\n");
	exit(0); 				   /* Terminate program! */
	}
	
	fp1= fopen("39.c","r");	/* open for reading */
	c = getc(fp1);			    /* file could be empty */
	counter1=0;
	while (c!=EOF)
	{
	putchar(c);
	counter1++;
	c=getc(fp1);
	}
	fclose(fp1);
	
	fp2= fopen("40.c","r");
	d = getc(fp2);
	counter2=0;
	while (c!=EOF)
	{
	putchar(d);
	counter2++;
	d=getc(fp2);
	}
	fclose(fp2);
	if(counter1!=counter2){printf("they aren't the same c1= %d\r\n c2 = %d\r\n",counter1,counter2);}
	if(counter1==counter2){printf("they are the same c1= %d\r\n c2 = %d\r\n",counter1,counter2);}
	
}