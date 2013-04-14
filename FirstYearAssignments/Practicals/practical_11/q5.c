/*Evan O'Keeffe
  10324289 
  practical 11 question5
  bit twiddling in C
*/
#include<stdio.h>

unsigned short i;
unsigned short swap_bytes(unsigned short i);//swap the last 2 digits with the first 2

int main()
{
	printf("Please enter a value for i in HEX\r\n");
	scanf("%4x",&i);//recieve a hex number and place in location i
	if(i>0)
	{
		printf("i=%x\r\n",i);//show what i was in hex form
		printf("answer=%x\r\n",swap_bytes(i));//show the conversion of i
		printf("\n");
		printf("bit swap=%X\r\n",swap_bytes(i));//final answer
	}
	else 
		printf("Your number was either not excepted or is negative\r\n");
		//this function of >> and << are only defined for positive integers
}
unsigned short swap_bytes(unsigned short i)
{	
	unsigned short a,b,c,d;
	a=i;
	b=i;
	c=i;
	d=i;
	a = (a << 8);//shift a by 8 bits and mask the left side with 0's
	b= (b >> 8);//shift a by 8 bits and mask the right side with 0's
	c *= 256;//showing that the >> operation is effectively just multiplying
	d /= 256;//showing that the << operation is effectively just dividing
	
	printf("c=%x,d=%x\r\n",c,d);
	i=a+b;//sum the a and b
	printf("a=%x,b=%x\r\n",a,b);
	return i; 
}