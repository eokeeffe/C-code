/*Evan O'Keeffe
  10324289
  takes a lower/uppercase word and transforms it into lowercase/uppercase word*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main()
{
    int buf=100;
	char s[buf],sl[buf],su[buf];
	int i=0,len;
	
	while(i++!=buf){s[i]=sl[i]=su[i]='\0';}
	i=0;
	
	printf("please enter your word\r\n");
	gets(s);
	len=strlen(s);
	printf("%s the lenght is %d\r\n",s,len);
	
	while(s[i]!='\0'){
	if(s[i]>='a'&&s[i]<='z'){
							 sl[i]=s[i]-32;
							 su[i]=s[i];
							 /*printf("your word is %s \r\n",sl);*/
							 printf("your word  %s \r\n has been changed to  %s \r\n",s,sl);
							}
	if(s[i]>='A'&&s[i]<='Z'){
							 su[i]=s[i]+32;
							 sl[i]=s[i];
							 /*printf(" your word is %s \r\n",su);*/
							 printf("your word  %s \r\n has been changed to  %s \r\n",s,su);
							}
							i++;
				if(s[i]<=1&&s[i]>=9){printf("you have entered numbers , please enter again\r\n");}
					 }
	printf("Thank you for using this :)\r\n");
	
	return 0;
}