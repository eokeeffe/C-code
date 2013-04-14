/*
	Tier 1 : Part 5	:	Question 6
*/
#include<stdio.h>
#include<string.h>

int main()
{
    char string[200],reversed_string[200];
    int loop_count=0,opposite_loop_count=0;
   
    printf("please enter the string to check\r\n");
    gets(string);
    opposite_loop_count=strlen(string)-1;
   
    while( opposite_loop_count >= 0)
    {
        reversed_string[loop_count]=string[opposite_loop_count];
        opposite_loop_count = opposite_loop_count-1;
        loop_count = loop_count+1;
    }
    reversed_string[loop_count]='\0';
	
	printf("reversed string is %s\r\n",reversed_string);
	return 0;
}