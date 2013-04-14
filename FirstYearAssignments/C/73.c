/*Evan O'Keeffe
  10324289
  my CAT function , works from the CMD*/
  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
main(argc, argv)
int argc;
char *argv[];
{
	FILE *fopen(),*fp;
	
	if(argc==1){filecopy(stdin);}/*if there are no arguements copy standard input from stdin*/
	else
		while(--argc>0)
		{
			if((fp=fopen(*++argv,"r"))!=NULL)
			{
				printf("myCAT:can't open %s\r\n",*argv);
				break;
			}
		
			else{filecopy(fp);fclose(fp);}
		}
}
filecopy(fp)/*copy the file to standard output*/
FILE *fp;
{
	int c;
	while((c=getc(fp))!=EOF){putc(c,stdout);}
}
				

