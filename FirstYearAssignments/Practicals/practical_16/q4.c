/*Evan O'Keeffe
  10324289
  practical16 question 4
  
  once I found out what to do , I added printing eveyrthing from character,string,dec,hex,oct,bin using myprintf function
  left out the float and double and complex as it isn't needed for he question
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdarg.h>
//base conversions for itoa
#define DEC 10
#define BIN 2
#define OCT 8
#define HEX 16
//error macro
#define ERROR printf("line:%d\r\n",__LINE__);

int myprintf(char* string,...)
{
	//ERROR
	int len;
	len=strlen(string);
	va_list ap;
	va_start(ap,string);
	//ERROR
	char LETTER;//for the character
	char CSTRING[len];//for the numbers
	char* STRING_ARRAY;//for the string
	int C;//grab the int value from va_arg
	int I;//counter for the loop
	for(I=0;I<len;I++)
	{
		if(string[I]=='%')
		{
			if(string[I+1]=='d'||string[I+1]=='i')//decimal or integer
			{
				//ERROR
				C=va_arg(ap,int);
				itoa(C,CSTRING,DEC);// the number has to be converted back to its ascii or else it will be interpreted by the
								    // putchar/puts  won't see it as the decimal value of an ascii value
				puts(CSTRING);
			}
		}
		if(string[I]=='%')//print binary
		{
			if(string[I+1]=='b')
			{
				//ERROR
				C=va_arg(ap,int);
				itoa(C,CSTRING,BIN);// the number has to be converted back to its ascii or else it will be interpreted by the
								    // putchar/puts  won't see it as the decimal value of an ascii value
				puts(CSTRING);
			}
		}
		if(string[I]=='%')
		{
			if(string[I+1]=='o'||string[I+1]=='O')//print octal
			{
				//ERROR
				C=va_arg(ap,int);
				itoa(C,CSTRING,OCT);// the number has to be converted back to its ascii or else it will be interpreted by the
								    // putchar/puts  won't see it as the decimal value of an ascii value
				puts(CSTRING);
			}
		}
		if(string[I]=='%')
		{
			if(string[I+1]=='h'||string[I+1]=='H')//print hex
			{
				//ERROR
				C=va_arg(ap,int);
				itoa(C,CSTRING,HEX);// the number has to be converted back to its ascii or else it will be interpreted by the
								    // putchar/puts  won't see it as the decimal value of an ascii value
				puts(CSTRING);
			}
		}
		if(string[I]=='%')
		{
			if(string[I+1]=='s')//print a string
			{
				//ERROR
				STRING_ARRAY = va_arg(ap,char*);
				puts(STRING_ARRAY);
			}
		}
		if(string[I]=='%')
		{
			if(string[I+1]=='c')//print a string
			{
				//ERROR
				LETTER = va_arg(ap,int);
				putchar(LETTER);
			}
		}
	}
	
}

int main()
{	
	int a,b;
	char c;
	char sample[100];
	printf("Please enter a number\r\n");
	scanf("%d%*c",&a);
	
	printf("Please enter another number\r\n");
	scanf("%d%*c",&b);
	
	printf("Please enter a string\r\n");
	scanf("%s%*c",&sample);
	
	printf("Please enter a character\r\n");
	scanf("%c",&c);
	
	printf("the numbers in DEC\r\n");
	myprintf("%d %d",a,b,0);
	printf("the numbers in HEX\r\n");
	myprintf("%h %H",a,b,0);
	printf("the numbers in OCT\r\n");
	myprintf("%o %O",a,b,0);
	printf("the numbers in BIN\r\n");
	myprintf("%b %b",a,b,0);
	printf("string printed here\r\n");
	myprintf("%s",sample,NULL);
	printf("character printed here\r\n");
	myprintf("%c",c,NULL);
	
	return 0;
}