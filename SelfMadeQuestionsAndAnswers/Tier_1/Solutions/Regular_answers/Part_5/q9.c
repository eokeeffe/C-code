/*
	Tier 1 : Part 5	:	Question 9
	
	See the use of functions already present is very handy and makes certain aspects 
	simpler
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
	
	printf("%s is the first input\r\n",string_1);
	printf("%s is the second input\r\n",string_2);
	
	strcat(string_1," ");	//less stress and more time to make something useful
	strcat(string_1,string_2);
	
	printf("%s is the first input + second input\r\n",string_1);
	printf("%s is the second input\r\n",string_2);
	
	return 0;
}