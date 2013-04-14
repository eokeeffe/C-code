/*Evan O'Keeffe
  10324289
  practical 15 question4
  uses 2 strings, one the users word , the other the reversed word
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void palindrome(void);
int main()
{
	palindrome();
	return 0 ;
}
void palindrome(void)
{
	char string[200],string2[200];
	int i=0,j;
	
	printf("please enter the string to check\r\n");
	gets(string);
	j=strlen(string)-1;//setting the reveresed letter point
	
	while(j>=0)//pass the word in reveresed order into the array
	{
		string2[i]=string[j];
		j=j-1;
		i=i+1;
	}
	string2[i]='\0';//place at the end 
	
	if(strcmp(string,string2)==0)
	{	printf("%s is a palindrome\r\n",string);}
	else if (strcmp(string,string2)!=0)
	{	printf("%s is not a palindrome\r\n");}
}