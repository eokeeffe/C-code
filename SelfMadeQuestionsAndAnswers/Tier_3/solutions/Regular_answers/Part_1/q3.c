/*
	Tier 3 : Part 1	:	Question 3
*/
#include<stdio.h>
#define two 2

int power_of_2_function( int user_number_for_power );

int main()
{
	int user_number_for_power , answer;
	
	printf("Please enter a number for the 2^power\r\n");
	while( scanf("%d",&user_number_for_power)!= 1)
	{
		fflush(stdin);
		printf("Please enter valid number\r\n");
	}
	
	answer = power_of_2_function ( user_number_for_power );
	
	printf("%d^%d = %d\r\n", two , user_number_for_power , answer);
	
	return 0;
}

int power_of_2_function( int user_number_for_power )
{
	int answer;
	
	answer = two << user_number_for_power;
	answer /= two;
	
	return answer ;
}