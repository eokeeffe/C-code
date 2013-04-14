/*
	Tier 2 : Part 10	:	Question 10
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define line printf("line:%d\r\n",__line__);

int pointer_string_swap(char *string_1,char *string_2);

int main()
{
	char string_1[50] , string_2[50];
	
	printf("Please enter string 1\r\n");
	fgets(string_1,50,stdin);
	
	printf("Please enter string 2\r\n");
	fgets(string_2,50,stdin);
	
	printf("string 1 : %s\r\n",string_1);
	printf("string 2 : %s\r\n",string_2);
	
	pointer_string_swap(string_1,string_2);
	
	printf("string 1 : %s\r\n",string_1);
	printf("string 2 : %s\r\n",string_2);
	
	return 0;
}

int pointer_string_swap(char *string_1,char *string_2)
{
	char *temporary_string_pointer_1,*temporary_string_pointer_2,*temporary_string_pointer_3;
	int loop_counter = 0;
	
	temporary_string_pointer_1 = string_1;
	temporary_string_pointer_2 = string_2;
	
	while(loop_counter < strlen(string_1) && loop_counter < strlen(string_2) )
	{
		// The string pointer points to each character
		// each character is then exchanged for the other
		// thus swapping the strings by incrementing the string pointers
		
		*temporary_string_pointer_3 = *temporary_string_pointer_1;
		
		*temporary_string_pointer_1 = *temporary_string_pointer_2;
		
		*temporary_string_pointer_2 = *temporary_string_pointer_3;
		
		*temporary_string_pointer_1++;
		*temporary_string_pointer_2++;
	
		loop_counter++;
	}
	
	
	
	return ;
}