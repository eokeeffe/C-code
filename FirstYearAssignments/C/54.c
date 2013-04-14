 /*Evan o'Keeffe
 10324289
 acts as a file checker for equal braces and equal brackets
 also checks for ;, ",spaces,upper and lower case characters*/
 /*this program reads the characters out line by line when*/
 /*the user wants to read the input file*/
 #include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

main()
{
	FILE *fopen(),*fp;
	int c;
	int cntr1=0,cntr2=0,cntr3=0;
	int cntr4=0,cntr5=0,cntr6=0;
	int cntr7=0,cntr8=0,cntr9=0;
	int cntr10=0,cntr11=0;
	int cntr12=0,cntr13=0,linecount1=0;
	int i=0,a=0,b=0;
	char right,on;
	char filename1[100];
	
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
	if(c=='/'){cntr12++;}
	if(c=='*'){cntr13++;}
	c=getc(fp);			
	}
	fclose(fp);
	
	
	/*printf("the program %s \r\n",filename1);*/
	/*printf("has %d '{' and %d '}'\r\n",cntr2,cntr3);
	  printf("and %d '(' and %d ')'\r\n",cntr4,cntr5);*/
	
	if(cntr2==cntr3&&cntr4==cntr5)		/*brackets have to equal and braces too*/
	{
	printf("Your Program is safe to use\r\n");
	}
	else
	{
	printf("Your Program isn't safe\r\n");
	printf("your program is %d characters long\r\n",cntr1);
	printf("has %d '{' and %d '}'\r\n",cntr2,cntr3);
	printf("and %d '(' and %d ')'\r\n",cntr4,cntr5);
	printf("and %d ';' and %d spaces\r\n",cntr6,cntr7);
	printf("and %d double quote marks  and %d double quote marks\r\n",cntr8,cntr9);
	printf("and %d A-Z characets\r\n",cntr10);
	printf("and %d a-z characters\r\n",cntr11);
	printf("%d '/' and %d '*' \r\n",cntr12,cntr13);
	}
	
	printf("do you want to see your file right now?\r\n");
	printf("y for yes n for no\r\n");
	scanf("%c",&right);
	
	if(right=='y')
	{
	c='a';					/*for here the c='a' is reseting c and then reinitializing it below as the c from above already equals EOF*/
	fp=fopen(filename1,"r");
	while(c!=EOF)
	{
	c=getc(fp);
	if(c=='\n'){a++;}
	if(a==10){a=1; scanf("%c",&on); }		/*when a = 10 means when it has read 10 lines it will reset on the 10th line*/
	putchar(c);
	}
	}
	if(on=='n'){exit(0);}
}