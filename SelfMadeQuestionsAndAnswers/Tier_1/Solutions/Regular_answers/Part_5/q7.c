/*
	Tier 1 : Part 5	:	Question 7
*/
#include<stdio.h>
#include<string.h>

int main()
{
    char string[200],reversed_string[200];
    int loop_count=0 , opposite_loop_count=0 , zero = 0 ;
   
    printf("please enter the string to check\r\n");
    gets(string);
    opposite_loop_count=strlen(string)-1;
   
    while( opposite_loop_count >= zero)
    {
        reversed_string[loop_count]=string[opposite_loop_count];
        opposite_loop_count = opposite_loop_count-1;
        loop_count = loop_count+1;
    }
    reversed_string[loop_count]='\0';
	
	printf("reversed string is %s\r\n",reversed_string);
	
	if(strcmp(string,reversed_string) == 0)
	{
		printf("%s is a palindrome\r\n",string);
		printf("%s : %s\r\n",string,reversed_string);
	}
	else
	{	
		printf("the string is not a palindrome \r\n");
	}
	
	return 0;
}