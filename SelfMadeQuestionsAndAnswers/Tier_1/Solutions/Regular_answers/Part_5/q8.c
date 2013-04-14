/*
	Tier 1 : Part 5	:	Question 8
	
	There are two ways of doing this , using strcat or by the manual way below
	personally though use strcat , saves time 
*/
#include<stdio.h>
#include<string.h>

int main()
{
    char string_1[20] , string_2[20], dummy;
    int loop_count=0 , loop_count_2 = 0 ,control_statement = 20 ;
	int zero = 0 , string_length_1 , string_length_2=0 ;
   
    printf("Please enter something for string 1\r\n");
	scanf("%s",&string_1);
	dummy=getchar();
	
	printf("Please enter something for string 2\r\n");
	scanf("%s",&string_2);
	dummy=getchar();
	
	loop_count_2 = string_length_1 = strlen(string_1);
	
	for(loop_count =0 ; loop_count_2 < control_statement ; loop_count++ , loop_count_2++)
	{
		string_1[loop_count_2] = string_2[loop_count];
	}
	
	printf("The strings are now concatenated %s \r\n", string_1 );
	
	return 0;
}