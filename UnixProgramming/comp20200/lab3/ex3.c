#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUMSIZE 14
int get_int();
char get_char();

int  main()
{
	//arrays for numbers
	char array[NUMSIZE];
	int next=0;
	
	printf("Please enter the number\r\n");
	for (next = 0 ; next < 13 ; next++)
	{
		array[next]=get_char();
	}
	
	for (next=0; next < strlen(array);next++)
	{
		if(next==4){printf(".");}
		if(next==10){printf(".");}
		if(next==13){printf(".");}
		if(array[next]!='('&&array[next]!=')'&&array[next]!='-')
		{
		putchar(array[next]);
		}
	}
	printf("\r\n");
	return 0;
}
int get_int()
{	
	int number=0;
	while(scanf("%d",&number) != 1)
	{
		printf("please enter a number\r\n");
		fflush(stdin);
	}
	return number;
}
char get_char()
{
	char c;
	while(scanf("%c%*c",&c) != 1)
	{
		printf("please enter a character\r\n");
		fflush(stdin);
	}
	return c;
}
