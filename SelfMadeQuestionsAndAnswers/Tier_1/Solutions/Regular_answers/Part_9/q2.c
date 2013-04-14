/*
	Tier 1 : Part 9	:	Question 2
	
*/
#include<stdio.h>
#include<stdlib.h>

int function(int number_1,float number_2,double number_3);

int main()
{
	int number_1;
	float number_2;
	double number_3;
	
	number_1 = 2;
	number_2 = 4.5;
	number_3 = 8.5466;
	
	function(number_1,number_2,number_3);

	return 0;
}

int function(int number_1,float number_2,double number_3)
{
	printf("see the function works \r\n");
	printf("Your 3 data types %d %f and %lf\r\n",number_1,number_2,number_3);
	
	return 0;
}