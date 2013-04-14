/*
	Tier 1 : Part 3	:Extra 	Question 1
	
	This question should have been quite easy if you have aready done
	question 10 , same method just different controls
*/
#include<stdio.h>

int main()
{
	int loop_count = 0 , control_statement = 3 ;
	
	while(( printf("HELLO WORLD\r\n") )&& (loop_count < control_statement) )
	{	loop_count++;	}
	
	return 0;
}