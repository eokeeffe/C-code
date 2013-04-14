/*
	Tier 3 : Part 4	:	Question 7
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<signal.h>

int square_root();
int input();

int square_root()
{
	int number;
	float answer;
	
	number = input();
	answer = sqrt(number);
	
	if(number<0)
	{
		fprintf(stderr,"%d %s\r\n",errno,strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("the answer is = %f \r\n",answer);
		return 0;
	}
		
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