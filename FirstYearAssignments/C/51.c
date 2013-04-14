 /*Evan o'Keeffe
 10324289
 acts as a file checker for equal braces and equal brackets
 also checks for ;, ",spaces,upper and lower case characters*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

void main()
{
	FILE *fopen(),*fp;
	int c;
	int cntr1=0,cntr2=0,cntr3=0;
	int cntr4=0,cntr5=0,cntr6=0;
	int cntr7=0,cntr8=0,cntr9=0;
	int cntr10=0,cntr11=0;
	char right;
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
	if(c==';'){cntr6++;}
	if(c=='\n'){cntr7++;}
	if(c=='"'){cntr8++;}
	if(c=='"'){cntr9++;}
	if(c>='A'&&c<='Z'){cntr10++;}
	if(c>='a'&&c<='z'){cntr11++;}
	c=getc(fp);			
	}
	fclose(fp);
	
	
	/*printf("the program %s \r\n",filename1);*/
	/*printf("has %d '{' and %d '}'\r\n",cntr2,cntr3);
	  printf("and %d '(' and %d ')'\r\n",cntr4,cntr5);*/
	
	if(cntr2==cntr3&&cntr4==cntr5)
	{
	printf("Your Program is safe to use\r\n");
	}
	else
	{
	printf("Your Program isn't safe\r\n");
	printf("here are your problems\r\n");
	printf("your program is %d characters long\r\n",cntr1);
	printf("has %d '{' and %d '}'\r\n",cntr2,cntr3);
	printf("and %d '(' and %d ')'\r\n",cntr4,cntr5);
	printf("and %d ';' and %d spaces\r\n",cntr6,cntr7);
	printf("and %d double quote marks  and %d double quote marks\r\n",cntr8,cntr9);
	printf("and %d A-Z characets\r\n",cntr10);
	printf("and %d a-z characters\r\n",cntr11);
	
	
	printf("do you want to see your file right now?\r\n");
	printf("y for yes n for no\r\n");
	scanf("%c",&right);
	/*right=getchar();*/
	
	if(right=='y')
	{
	c='a';
	fp=fopen(filename1,"r"); 
	while (c!=EOF)
	{
	c=getc(fp);	
	putchar(c);	
	}
	fclose(fp);
	}
	if(right=='n')
	{
	EVAN();
	exit(0);
	}
	}
	
}
EVAN()
{printf("hello\r\n");
}
