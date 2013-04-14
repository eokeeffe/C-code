/*
	Tier 1 : Part 7	:	Question 5
	
	The basic way this works is by taking the remainder of the number
	and plaing it in an array
	The number is divided by 2 as binary is base 2 , if the remainder is 0
	then 0 is placed in the array
	if the remainder is not 0 then its 1 and its placed in the array 
	the array is then printed backwards to make sure that the binary sequence
	is printed in the right order
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int user_input , loop_count=0 , print_loop_count , divisor;
	int binary_output[40],clean_array;
	
	for(clean_array=0;clean_array<40;clean_array++){binary_output[clean_array]=0;}
	
	printf("Please enter the number you want converted to binary\r\n");
	scanf("%d%*c",&user_input);
	
	divisor=user_input;
	
	while(divisor > 0 )
	{
		if(divisor%2==0)
		{
			binary_output[loop_count]=0;
			loop_count++;
		}
		else
			{
				binary_output[loop_count]=1;
				loop_count++;
			}
		
		divisor/=2;
	}
	
	print_loop_count = loop_count;
	printf("%d has been converted to ",user_input);
	while(print_loop_count>=0)
	{
		printf("%d",binary_output[print_loop_count]);
		print_loop_count--;
	}
	
	return 0;
}