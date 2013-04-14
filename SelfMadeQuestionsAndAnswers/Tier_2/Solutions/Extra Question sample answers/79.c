/*
	Tier 2 : Extra_Question	:	Question 79
	
	GCD is found by taking the remainder and quotient of dividing a large number by another 
	number
	
	The GCD is the last number before the quotient is zero
	so in this case its 3
	
	Example :	find the GCD of 289 and 151
	
				289|quot|
				151|1	|
	remainder 1	138|1	|
	remainder 2	 13|10	|
	remainder 3	  8|1	|
	remainder 4	  5|1	|
remainder 5	GCD-> 3|1	|
		          2|0	|
*/
#include <stdio.h>
#define LINE printf("line number %d \r\n",__LINE__);

int GCD_SETUP(int number_to_divide_by , int dividsor);
int GCD(int previous_remainder , int remainder);

int user_number_1 , user_number_2;

int main()
{
	user_number_1=0 ;
	user_number_2=0 ;
	
	printf("Please enter the divident number\r\n");
	scanf("%d",&user_number_1);
	
	printf("Please enter the divisor number\r\n");
	scanf("%d",&user_number_2);
	
	GCD_SETUP(user_number_1,user_number_2);
	
	return 0;
}
int GCD_SETUP(int number_to_divide_by , int divisor)
{
	
	if(number_to_divide_by==0) // simple thing to speed up function
	{
		printf("GCD = 0\r\n");
		return 0;
	}
	if(divisor==0)//check for illegal division by zero
	{
		printf("Illegal division by zero\r\n");
		return 0;
	}
	if(divisor > number_to_divide_by)//the largest number must be divided
	{
		int temp=0;
		temp= divisor;
		divisor = number_to_divide_by;
		number_to_divide_by = temp;
	}
	else
		{
			int previous_remainder = divisor;
			int remainder  = (number_to_divide_by % divisor);
			
			GCD(previous_remainder,remainder);
		}
	return 0;
}

int GCD(int previous_remainder , int remainder )
{
	int quotient;
	
	if(remainder!=0)
	{
		quotient = previous_remainder / remainder;
	}
	
	if(quotient == 0 || remainder == 1)
	{
		printf("GCD of %d and %d is %d \r\n",user_number_1,user_number_2,previous_remainder);
		return 0;
	}
	else
	{
		
		previous_remainder %= remainder;
		
		remainder %= previous_remainder;
		
		printf("pr:%d , r:%d\r\n",previous_remainder,remainder);
		
		GCD(previous_remainder,remainder);
	}
}