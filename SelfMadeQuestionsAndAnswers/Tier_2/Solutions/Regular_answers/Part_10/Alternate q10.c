/*
	Tier 2 : Part 10	:	Question 10
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define line printf("line:%d\r\n",__line__);

int pointer_string_sort(char *string_1,char *string_2);

int main()
{
	char string_1[50] , string_2[50];
	
	printf("Please enter string 1\r\n");
	fgets(string_1,50,stdin);
	
	printf("Please enter string 2\r\n");
	fgets(string_2,50,stdin);
	
	printf("string 1 : %s\r\n",string_1);
	printf("string 2 : %s\r\n",string_2);
	
	pointer_string_sort(string_1,string_2);
	
	printf("string 1 : %s\r\n",string_1);
	printf("string 2 : %s\r\n",string_2);
	
	return 0;
}

int pointer_string_sort(char *string_1,char *string_2)
{
	char *temporary_pointer = (char*)malloc((strlen(string_1)+1)*sizeof(char));
	
	strcpy(temporary_pointer,string_1);
	strcpy(string_1,string_2);
	strcpy(string_2,temporary_pointer);
	
	free(temporary_pointer);
	
	return ;
}