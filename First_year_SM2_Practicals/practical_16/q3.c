/*Evan O'Keeffe
  10324289
  practical16 question3
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

#define ERROR printf("line:%d\r\n",__LINE__);

int myprintf(char* string,...)
{
	va_list ap;
	va_start(ap,string);
	char STRING_ARRAY[100];
	int COUNT=0,C,I;
	for(I=0;I<100;I++){STRING_ARRAY[I]='\0';}
	
	if(string[0]=='%'&&string[1]!='d')
	{
		printf("string[%d]=%c,string[%d]=%c\r\n",0,string[0],1,string[1]);
		printf("Mal-formed statement, please look at the function\r\n");
		return 0;
	}
	if(string[0]=='%'&&string[1]=='d')
	{
		//ERROR
		for(COUNT=0;C!='\0';COUNT++)
		{
			//ERROR
			C=va_arg(ap,int);
			itoa(C,STRING_ARRAY,DEC);
			//printf("%s",STRING_ARRAY);
			puts(STRING_ARRAY);
		}
		return 1;
	}
	else
	{
		ERROR
		return 0;
	}
}

int main()
{	
	int a;
	printf("Please enter a number\r\n");
	scanf("%d%*c",&a);
	myprintf("%d",a,NULL);
	return 0;
}