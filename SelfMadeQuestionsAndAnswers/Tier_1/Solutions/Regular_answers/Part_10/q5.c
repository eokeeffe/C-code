/*
	Tier 1 : Part 10	:	Question 5
	
*/
#include<stdio.h>
#include<string.h>

struct Date
{
	int day;
	int month;
	int year;
	int year_day;
	char month_name[12];
	
}Date_accessor_1;

int main()
{
	int month=0,accumulated_days=0,year=0;
	
	printf("Enter the month name\r\n");
	gets(Date_accessor_1.month_name);
	
	printf("Please enter the month number\r\n");
	scanf("%d",&Date_accessor_1.month);
	if(Date_accessor_1.month<1){printf("negative value , closing program\r\n");return 0;}
	
	printf("Please enter the day number\r\n");
	scanf("%d",&Date_accessor_1.day);
	if(Date_accessor_1.day<1){printf("negative value , closing program\r\n");return 0;}
	
	printf("Please enter the Year\r\n");
	scanf("%d",&Date_accessor_1.year);
	if(Date_accessor_1.year<1){printf("negative value , closing program\r\n");return 0;}
	
	printf("Please enter the year day e.g 215th day of the year\r\n");
	scanf("%d",&Date_accessor_1.year_day);
	if(Date_accessor_1.year_day<1){printf("negative value , closing program\r\n");return 0;}
	
	printf("The year is %d\r\n",Date_accessor_1.year);
	printf("The day is %d of the week \r\n",Date_accessor_1.month);
	printf("The year day is %d \r\n",Date_accessor_1.year_day);
	printf("The month name is %s \r\n",Date_accessor_1.month_name);
	printf("The month number if %d\r\n",Date_accessor_1.month);
	
	return 0;
}