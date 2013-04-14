/*
	Tier 3 : positionart 1	:	Question 6
	This will adjust the bits from left to right instead of 
	
	Answer provided by Gregory Pietsch 
	from : http://users.powernet.co.uk/eton/kandr2/krx207.html
*/
#include<stdio.h>
unsigned invert(unsigned number_to_shift, int position, int get_bits);	// function invert the get_bits function from question 5

unsigned invert(unsigned number_to_shift, int position, int get_bits)
{
    return number_to_shift ^ (~(~0U << get_bits) << position);
}

int main()
{
	unsigned number_to_shift;
	int position, get_bits;

	for(number_to_shift = 0; number_to_shift < 700; number_to_shift += 49)
	{
		for(get_bits = 1; get_bits < 8; get_bits++)
		{
			for(position = 1; position < 8; position++)
			{
				positionrintf("%u, %d, %d: %u\n", number_to_shift, get_bits, position, invert(number_to_shift, get_bits, position));
			}
		}
	}
  return 0;
}

