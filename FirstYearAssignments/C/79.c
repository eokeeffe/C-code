/*Evan O'Keeffe
  10324289
  my type program with readout capability*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void file_check(FILE *fp);
void readout(FILE *fp,char *argv[]);

main(int argc, char *argv[])
{
	FILE *fopen(),*fp;	
	int i;
	
	fp = fopen ( argv[1] , "r" );
	file_check(fp);
	readout(fp,argv);
	
	exit(0);
}
void file_check(FILE *fp)
{
	if(fp==NULL)
		{	
			printf("Cannot open %s for reading \r\n",fp);
			exit(0);
		}
}
void readout(FILE *fp,char *argv[])
{
	char right,on;
	int c,i,a=0;
	
	printf("do you want to see more of your file right now?\r\n");
	printf("y for yes n for no\r\n");
	scanf("%c",&right);
	
	if(right=='y')
	{				
	fp = fopen ( argv[1] , "r" );
	while(c!=EOF)
	{
	c=getc(fp);
	if(c=='\n'){a++;}
	if(a==10){a=1; scanf("%c",&on); }		/*when a = 10 means when it has read 10 lines it will reset on the 10th line*/
	putchar(c);
	}
	}
	if(on=='n'){fclose(fp);exit(0);}
	fclose(fp);
}