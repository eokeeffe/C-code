/*
	Tier 2 : Part 8	:	Question 2
	
*/
#include "myheader_q2.h"

int main()
{
	char user_string[100];
	int number;
	
	clear_screen();
	
	printf("Please enter an int\r\n");
	number = my_int_scanf();
	
	printf("%d was the number you entered\r\n",number);
	
	printf("\r\n please enter a string \r\n");
	my_gets(user_string,100);
	
	printf("the string you entered was %s\r\n",user_string);
	
	return 0;
}