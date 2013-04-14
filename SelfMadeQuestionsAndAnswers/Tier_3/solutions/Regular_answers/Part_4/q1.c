/*
	Tier 3 : Part 4	:	Question 1
*/
#include<stdio.h>
#include<stdlib.h>

int divide();
int input_1();
int input_2();

int divide()
{
	int number,divisor,answer;
	
	number=input_1();
	divisor=input_2();
	
	if(divisor == 0)//simplest way to deal with the problem is to check it
	{
		printf("cannot divide by zero\r\n");
		exit(0);
	}
	else
	{
		answer = number / divisor;
		
		printf("The answer of %d/%d is %d\r\n",number,divisor,answer);
	}
	return 0;
}

int input_1()
{
	int user_number;
	
	printf("Please enter the number to divide\r\n");
	while(scanf("%d",&user_number)!=1)
	{
		printf("Please enter an integer\r\n");
		fflush(stdin);
	}
	
	return user_number;
}

int input_2()
{
	int user_divisor;
	
	printf("Please enter the number to divide by\r\n");
	while(scanf("%d",&user_divisor)!=1)
	{
		printf("Please enter an integer\r\n");
		fflush(stdin);
	}
	
	return user_divisor;
}


int main ()
{
	divide();
	return 0;
}