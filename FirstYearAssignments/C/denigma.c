/*Evan O'Keeffe
  10324289
  this program decodes the enigma cipher produced by the 
  enigma program from earlier, it isn't perfect due to the reversal problem 
  it produces a fairly identical to pre-encoded message apart from some small artifeccts
  
  */
  
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>

void clear_screen(void);
void get_option(void);
void wait_for_user(void);
void caesarshift1(int n);
char readfile(void);
void writetofile(char b[]);				/*kept all the characters in the lowercase form when doing the wraparound for the shift*/
char sl[1000];

void clear_screen(void)
{
	int i;
	for(i=0;i<24;i++)
	printf("\n");
}

void get_option(void)
{
	int i=0,n=0;
	int valid=0;
	
	printf("what was the shift?\r\n");
	scanf("%d",&n);
	while(n<0||n>=26)
	{
	printf("what was the shift?\r\n");
	scanf("%d",&n);
	}
		caesarshift1(n);
}

void wait_for_user(void)								/*added during the debug phase to check for internal errors*/
{
	char dummy[80];
	printf("\n\n Press Return to continue:\r\n");
	gets(dummy);
}

void caesarshift1(int n)			/*actual routine for the encrytion*/
{
	
	char b[1000];
	int  z=0,i=0;
	
	while(z++!=1000){ b[z]='\0';}
	
	printf("the shift was %d \r\n",n);		/*debug feature*/
	
	readfile();
	printf("first stage complete\r\n");				/*debug feature*/
	/*printf("string converted to %s\r\n",sl);*/		/*debug feature*/
	
	while(sl[i]!='\0')
	{
		b[i]=sl[i]-n;
		if(b[i]>=255){b[i]=b[i]-255;}								/*pretty much the wraparound to stop charaters going above 122(z)*/		
		i++;
	}
	b[i]='\0';
	printf("encoding complete\r\n");
	/*printf("your string %s has now been encoded\r\n",sl);*/
	printf("your encoded string is %s\r\n",b);
	
	writetofile(b);
}

char readfile()
{
	FILE *fopen(),*fp;
	char fname[200],a[1000],pattern[200],replace[200];
	int c=0,i=0,j=0,d=0,e=0;
	
	wait_for_user();
	printf("please enter the name of the file to encrpyt\r\n");
	gets(fname);
	fp=fopen(fname,"r");
	
	if(fp==NULL){printf("this file doesn't exist\r\n");}
	
	while(j++!=1000){a[j]='\0';}
	while(e++!=1000){sl[e]='\0';}
	
	c=getc(fp);
	while(c!=EOF)
	{
		c=getc(fp);										/*basically whats happening here is im copying this*/
		a[i]=c;											/*files pieces into the array for ease of use for the next few steps*/
		i++;
	}
	/*printf("the lenght of the file is %d\r\n",i);*/
	fgets(a,999,fp);
	/*printf("a=%s\r\n",a);*/
	d=strlen(a);
	/*printf("the lenght of a=%d\r\n",d);*/
	i=0;										/*reinitialize for the next loop*/
	
	while(a[i]!='\0')
	{	
		if(a[i]>='A'&&a[i]<='Z')
			{
				sl[i]=a[i]+32;
				/*printf("your word  %s \r\n has been changed to  %s \r\n",a,sl);*/		/*debug feature*/
			}
			else{sl[i]=a[i];}
			i++;
			if(a[i]<=1&&a[i]>=9){printf("you have entered numbers , please enter again\r\n");exit(0);}
	}
	fclose(fp);
	printf("lowercase check1 is %s\r\n",sl);					/*originally a debug feature from the previous program , it came in useful here when i wanted to 
																   ask for the letters/words to be replaced by the user, they can see what words they want changed*/
	
	printf("Enter pattern: \r\n");
	gets( pattern );
	printf("Enter replacement: \r\n");
	gets( replace );
	while(pattern[0]!='q')
	{
	printf("Enter pattern: \r\n");
	printf("or press q to stop replacing\r\n");
	gets( pattern );
	printf("Enter replacement: \r\n");
	gets( replace );
	i = 0 ;
	while ( sl[i] != '\0' )		/* not at end of string */
	{
		if ( sl[i] == pattern[0] )	/*Single char pattern */
		{
			putchar(replace[0]);
		}
		else if ( sl[i] != pattern[0] )
		{
			putchar(sl[i]) ;
		}
		
		i = i + 1;
	}
	putchar('\n') ;
	}
	return(*sl);
}
void writetofile(char b[])
{
	FILE *fopen(),*ftw;
	char towrite[200];
	
	printf("please enter the name you want for the decrpyted file\r\n");
	gets(towrite);
	ftw=fopen(towrite,"w");
	fprintf(ftw,"%s",b);
	if(ftw==NULL){printf("error file wasn't written to\r\n");}
	exit(0);
}
void main()
{
	clear_screen();
	get_option();
}