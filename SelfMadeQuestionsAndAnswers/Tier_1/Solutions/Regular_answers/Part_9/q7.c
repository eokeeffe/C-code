/*
	Tier 1 : Part 9	:	Question 7
	
*/
#include<stdio.h>

int seconds_to_mintues(int seconds);

int main()
{
	int seconds;
	
	printf("Please enter a number for seconds\r\n");
	scanf("%d",&seconds);
	
	printf("%d minutes in %d seconds\r\n",seconds_to_mintues(seconds),seconds);
	return 0;
}

int seconds_to_mintues(int seconds)
{
	int minutes;
	minutes = seconds/60;
	return minutes;
}