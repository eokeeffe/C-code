/*
	Tier 3 : Part 4	:	Question 2
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<errno.h>

int square_root();
int input();

int square_root()
{
	errno=0;
	int number;
	float answer;
	
	number = input();
	answer = sqrt(number);
	
	if(errno == 0)//simplest way to deal with the problem is to check it
	{
		printf("%d is the answer \r\n",answer);
		exit(0);
	}
	else
	{
		fprintf(stderr,"%d is the error code \r\n",errno);
		fprintf(stderr,"%s \r\n","Cannot square root a minus number");
	}
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