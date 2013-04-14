/*Evan O'Keeffe
  10324289
  my type program with readout capability for 3 arguements*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void file_check(FILE *fp);
void readout(FILE *fp);

main(int argc, char *argv[])
{
	FILE *fopen(),*fp;	
	char choice[200];
	int i;
	
	printf("do you want the (F)irst, (S)econd or (T)hird program first?\r\nor Q for quit\r\n");
	scanf("%c",&choice);
	while(choice!="q")
	{
	if(choice=="f"||choice=="F"){fp = fopen ( argv[1] , "r" );file_check(fp);readout(fp);}
	else if(choice=="s"||choice=="S"){fp = fopen ( argv[2] , "r" );file_check(fp);readout(fp);}
	else
	{fp = fopen ( argv[3] , "r" );file_check(fp);readout(fp);}
	}
	
	
	exit(0);
}
void file_check(FILE *fp)
{
	if(fp==NULL)
		{	
			printf("Cannot open %s for reading \r\n",*fp);
			exit(0);
		}
}
void readout(FILE *fp)
{
	char right,on;
	int c,i,a=0;
	
	printf("do you want to see more of your file right now?\r\n");
	printf("y for yes n for no\r\n");
	scanf("%c",&right);
	
	if(right=='y')
	{				
		while(c!=EOF)
		{
		c=getc(fp);
		if(c=='\n'){a++;}
		if(a==10){a=1; scanf("%c",&on);if(on=='n'||on=='N'){exit(0);} }		/*when a = 10 means when it has read 10 lines it will reset on the 10th line*/
		putchar(c);
		if(c==EOF){exit(0);}
		}
		if(c==EOF){exit(0);}
	}
	if(on=='n'||on=='N'){exit(0);}
	fclose(fp);
}