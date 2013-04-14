/*Evan o'keeffe
  10324289
  Program that reads the string and counts the amount of spaces in it*/

#include<stdio.h>

main()
{ 
	char text[20];
	int i,sum,count;
	
	printf("please enter your word\r\n");
	gets(text);
	
	i=count=0;
	sum=0;

	if(text[i]<' '){printf("there was no characters\r\n");}
	{
	   while(text[i]!= '\0')
	 { if(text[i]==' '){
	   count=count+1;
	   printf("there was characters\r\n");}
		{
		i=i+1;
		}
	 }
	}
	 printf("the space character appears %d times in the string %s\r\n",count,text);
	 
	 return 0;
}
  