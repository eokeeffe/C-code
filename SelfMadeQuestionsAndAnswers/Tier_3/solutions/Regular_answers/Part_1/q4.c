/*
	Tier 3 : Part 1	:	Question 4
*/
#include<stdio.h>

unsigned short swap_bytes(unsigned short user_hex_number);//swap the last 2 digits with the first 2

int main()
{
	unsigned short user_hex_number;
	
	printf("Please enter a value for i in HEX\r\n");
	scanf("%4x",&user_hex_number);//recieve a hex number and place in location i
	if(user_hex_number>0)
	{
		printf("user_hex_number=%x\r\n",user_hex_number);//show what i was in hex form
		
		printf("bit swap=%X\r\n",swap_bytes(user_hex_number));//final answer
	}
	else 
		printf("Your number was either not excepted or is negative\r\n");
		//this function of >> and << are only defined for positive integers
		
	return 0;
}
unsigned short swap_bytes(unsigned short user_hex_number)
{	
	unsigned short left_shift,right_shift,example_left_shift,example_right_shift;
	
	left_shift = user_hex_number;
	right_shift = user_hex_number;
	
	example_left_shift = user_hex_number;
	example_right_shift = user_hex_number;
	
	left_shift = (left_shift << 8);//shift by 8 bits and mask the left side with 0's
	right_shift = (right_shift >> 8);//shift by 8 bits and mask the right side with 0's
	
	example_left_shift *= 256;//showing that the >> operation is effectively just multiplying by 2^8
	example_left_shift /= 256;//showing that the << operation is effectively just dividing by 2^8
	
	//printf("example_left_shift = %x,example_left_shift = %x\r\n",example_left_shift,example_right_shift);
	
	user_hex_number = left_shift + right_shift;//sum the left and right shifts
	
	//printf("left_shift = %x , right_shift = %x\r\n",left_shift,right_shift);
	
	return user_hex_number; 
}