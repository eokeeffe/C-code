/*Evan o'Keeffe
 10324289
 this program is used for the fgets and fscanf functions */
 /*the reason i made this is so that the strings written are fully known */
 /*i.e i know that there is a \r\n or whatever at the end*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

main()
{
	FILE *fopen(),*fp;
	char fn[100];
	char p1[20];
	int c=0,a=0,b;
	
	printf("please enter the file to written to \r\n");
	gets(fn);
	if(fp==NULL){printf("the file %s is either wrong type or is empty\r\n",fn);}
	fp=fopen(fn,"w");
	printf("how many words do you want to write?\r\n");
	scanf("%d",&b);
	
	while(c<b)
	{
	while(a<20){p1[a++]='\0';}/*clears the buffer*/
	c++;
	a=0;
	printf("please enter the word you want\r\n");
	gets(p1);
	
	a=0;
	fprintf(fp,"%s\n",p1);
	}
	fclose(fp);
}
	