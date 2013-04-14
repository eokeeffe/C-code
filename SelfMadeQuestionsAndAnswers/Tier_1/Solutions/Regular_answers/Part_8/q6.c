/*
	Tier 1 : Part 8	:	Question 6
	This is a simple function to get the power of a number the user enters
	
	Does a quick check to make sure that power if the power is 0 then return 1 as anything to the 
	power of zero is 1 
	
	This is a recursive function that will multiply the first number by itself 
	a number of times until the power_of variable hits 0 it then returns the value
*/
#include<stdio.h>
#include<stdlib.h>

unsigned int func(unsigned int user_number,unsigned int power_of)
{	
	unsigned int answer;
	if(power_of <= 0){return 1;}
	else
	{ 
		answer = user_number * func( user_number , power_of-1 );
		return answer;
	}
}

int main()
{
	unsigned int user_number,power_of;
	
	printf("Please enter a number here\r\n");
	scanf("%d",&user_number);
	
	printf("Please enter the power of the first number here\r\n");
	scanf("%d",&power_of);
	
	printf("%d is the number returned \r\n",func(user_number,power_of) );
	return 0;
}