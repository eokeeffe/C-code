/*Evan O'Keeffe
  10324289
  question2 practical 10
*/
#define true 1
#define false 0
#include<stdio.h>

int check_file(FILE *fpt);
void main()
{
	FILE *fpt;
	int c=0;
	char dummy;
	fpt=fopen("sample.dat","r");
	dummy=getchar();
	
	if(check_file(fpt)!=true)
	{
		c=getc(fpt);
		while(c!=EOF)
		{
			c=getc(fpt);
			putchar(c);
		}
		fclose(fpt);
	}
	else
		{
			fclose(fpt);
			printf("sorry but your file wasn't read\r\n");
			main();
		}
}

int check_file(FILE *fpt)
{
	if(fpt==NULL){return true;}
	if(fpt!=NULL){return false;}
}
