/*
	Tier 3 : Part 4	:	Question 5
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<errno.h>
#include<assert.h>

int square_root();
int input();

int square_root()
{
	errno=0;
	
	int number;
	float answer;
	
	number = input();
	answer = sqrt(number);
	
	assert(errno==0);
	
	printf("the answer is = %f \r\n",answer);
	return 0;
}

int input()
{
	int user_number;
	
	printf("Please enter the number to square root\r\n");
	while(scanf("%d",&user_number)!=1)
	{
		printf("Please enter an integer\r\n");
		fflush(stdin);
	}
	
	return user_number;
}


int main ()
{
	square_root();
	return 0;
}