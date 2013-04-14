/*
	Tier 1 : Part 9	:	Question 1
	
*/#include<stdio.h>
#include<stdlib.h>

int number_swap(int number_1,int number_2);

int main()
{
	int number_1,number_2;
	
	printf("Please enter the first number\r\n");
	scanf("%d%*c",&number_1);
	printf("Please enter the second number\r\n");
	scanf("%d%*c",&number_2);
	
	printf("Order before function %d %d\r\n",number_1,number_2);
	
	number_swap(number_1,number_2);

	return 0;
}

int number_swap(int number_1,int number_2)
{
	int temporary_variable=0;
	//I would memorzie this method 
	//its a simple bubble sort method for sorting , youll see it later
	temporary_variable = number_1;
	number_1 = number_2;
	number_2 = temporary_variable;
	
	printf("Order at the end of the function %d %d\r\n",number_1,number_2);
	return 0;
}
