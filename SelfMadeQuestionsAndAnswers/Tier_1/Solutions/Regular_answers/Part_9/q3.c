/*
	Tier 1 : Part 9	:	Question 3
	
*/
#include<stdio.h>
#include<time.h>

int date_and_time();

int main()
{
	date_and_time();
	return 0;
}

int date_and_time()
{
	time_t mytime;
	mytime = time(NULL);
	printf(ctime(&mytime));
	
	return 0;
}