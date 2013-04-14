/*Evan O'Keeffe
  10324289
  practical 15 question2
  using the strcmp function I simply take a 2 words
  then shows which is smaller and larger
  first is small and second is large
*/
#include<stdio.h>
void arrange(char* string1,char* string2);
int main()
{
	char string1[20];
	char string2[20];
	printf("enter a word\r\n");
	scanf("%19s",&string1);
	printf("enter another word\r\n");
	scanf("%19s",&string2);
	arrange(string1,string2);
	return 0;
}
void arrange(char* string1,char* string2)
{
	char* sort[10];
	printf("\n\n");
	//printf("%s %s\r\n",string1,string2);
	if(strcmp(string1,string2)==0){printf("%s\n%s\r\n",string1,string2);}
	if(strcmp(string1,string2)==1){printf("%s\n%s\r\n",string2,string1);}
	if(strcmp(string1,string2)==-1){printf("%s\n%s\r\n",string1,string2);}
}