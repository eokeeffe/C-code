/*Evan O'Keeffe
  10324289
  This is a caesar shift encoder
  basically what happens is that a string of characters is read in
  then the characters are shifted by a n number of positions
  
  V2.0 allows the reading in of a file then the writing of the encoded one to another file
  because of files being involved i decided that a caesaer cipher (historically 13 shifts)
  isn't exactly right with the addition of all  the other ascii characters 
  therefore i have made the wraparound the whole 255 of the character range
  
  Also the program will ask for the file name for the KEY output, so the person on the other end can decryt the message
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
void keylog(int n);						/*log the shift number in this case to another file*/
char sl[1000];

void clear_screen(void)					/*makes reading it far easier*/
{
	int i;
	for(i=0;i<24;i++)
	printf("\n");
}

void get_option(void)		
{
	int i=0,n=0;
	int valid=0;
	
	printf("how much do you want to shift by?\r\n");
	scanf("%d",&n);
	while(n<0||n>=26)			/*the reason i left this in the range of 0-26 was just for purpose of easier decrytion on the other end*/
	{
	printf("how much do you want to shift by?\r\n");
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
	
	printf("the shift you want is %d \r\n",n);		/*debug feature*/
	
	readfile();
	printf("first stage complete\r\n");				/*debug feature*/
	/*printf("string converted to %s\r\n",sl);*/		/*debug feature*/
	
	while(sl[i]!='\0')
	{
		b[i]=sl[i]+n;
		if(b[i]>=255){b[i]=b[i]-255;}								/*pretty much the wraparound to stop charaters going above 122(z)*/		
		i++;
	}
	b[i]='\0';
	printf("encoding complete\r\n");
	/*printf("your string %s has now been encoded\r\n",sl);*/
	/*printf("your encoded string is %s\r\n",b);*/
	keylog(n);												/*write the key to another file so that it can be safely kept to decrypt future messages*/
	writetofile(b);											/*write encryted message to a new file*/
	printf("all stages now complete\r\n");
}

char readfile()
{
	FILE *fopen(),*fp;
	char fname[200],a[1000];
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
	
	while(a[i]!='\0')			/*change all letters to lowercase*/
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
	printf("lowercase check1 is %s\r\n",sl);					/*originally a debug feature, i kept it for the knowledge of the user so they know they have the right file*/
	return(*sl);
}
void writetofile(char b[])
{
	FILE *fopen(),*ftw;
	char towrite[200];
	
	printf("please enter the name you want for the encrypted file\r\n");
	gets(towrite);
	ftw=fopen(towrite,"w");
	fprintf(ftw,"%s",b);
	if(ftw==NULL){printf("error file wasn't written to\r\n");}
	exit(0);
}
void keylog(int n)		/*so the person knows for later what there encrytion standard was*/
{
	FILE *fopen(),*key;
	char towrite[200];
	
	printf("please enter the name you want for the message key file\r\n");
	gets(towrite);
	key=fopen(towrite,"w");
	fprintf(key,"%d",n);
	if(key==NULL){printf("error file wasn't written to\r\n");}
}
void main()
{
	clear_screen();
	get_option();
}