/*
	Tier 3 : Part 4	:	Question 5
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<assert.h>

int add_the_numbers()
{
	int number_1 = 2073741823;
	int number_2 = 1073742824;
	int added_numbers;
	
	added_numbers = number_1 + number_2 ;
	
	printf("%d was first number \r\n",number_1);
	printf("%d was second number \r\n",number_2);
	
	
	if(added_numbers < 0)
	{
		printf("%d was the answer \r\n\n",added_numbers);
		
		fprintf(stderr,"%d is the error and '%s' is the error message\r\n",EDOM,strerror(EDOM));
		
		printf("The added numbers went beyond the maximum for a signed int value\r\n");
	}
	else
	{
		printf("%d was the answer \r\n",added_numbers);
	}
	return 0;
	
}	

int main ()
{
	add_the_numbers();
	
	return 0;
}