/*
	Tier 1 : Part 7	:	Question 10
	
	The basic idea here is that a leap year is directly divisble by 400 and if not
	then either 100 has to not be directly divisble and 4 is directly divisible 
	
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int user_year_input;
	
	printf("Please enter a year\r\n");
	scanf("%d%*c",&user_year_input);
	
	if(user_year_input%400 ==0 || (user_year_input%100 != 0 && user_year_input%4 == 0))
	{
		printf("Year %d is a leap year\r\n",user_year_input);
	}
	else
		{
			printf("Year %d is not a leap year\r\n",user_year_input);
		}
	return 0;
}
