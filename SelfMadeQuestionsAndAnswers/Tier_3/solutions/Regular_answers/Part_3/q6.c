/*
	Tier 3 : Part 3	:	Question 6
	Comments below to explain the program
*/
#include<stdio.h>
#include<time.h>
#include<string.h>

enum days_of_the_week
{
	monday,
	tuesday,
	wensday,
	thursday,
	friday,
	saturday,
	sunday
};

int get_real_day_of_week() // gets the real date by using string pointer functions
{
	time_t t;	// simply making a struct variable from the time_t struct
	time(&t);   // getting the current time from the system in the time.h function time()
	
	//printf("The current Date and Time is: %s\n", ctime(&t));
	
	if(strstr(ctime(&t),"Mon" ) != NULL )//this is a simple way of finding the date
	{									 // strstr returns a pointer to the occurence , so if something doesn't 
		return monday;						 // show up then it returns a null pointer
	}
	if(strstr(ctime(&t),"Tue" ) != NULL )
	{
		return tuesday;
	}
	if(strstr(ctime(&t),"Wen" ) != NULL )
	{
		return wensday;
	}
	if(strstr(ctime(&t),"Thu" ) != NULL )
	{
		return thursday;
	}
	if(strstr(ctime(&t),"Fri" ) != NULL )
	{
		return friday;
	}
	if(strstr(ctime(&t),"Sat" ) != NULL )
	{
		return saturday;
	}
	if(strstr(ctime(&t),"Sun" ) != NULL )
	{
		return sunday;
	}
	
}

int random_get_day_of_week()//will work but its better to get the real date
{
	srand(time(NULL));

	int random_number;
	random_number = rand()%7;
	return random_number;
}

int print_special(int day)//simply holds the switch statement that will print the dat and pizza special
{
	switch(day)
	{
	
		case monday:
		{
			printf("The real day is Monday \r\n");
			printf("The pizza is jerked meat supreme \r\n");
			break;
		}
		case tuesday:
		{
			printf("The real day is Tuesday \r\n");
			printf("The pizza is vegetarian supreme \r\n");
			break;
		}
		case wensday:
		{
			printf("The real day is Wensday \r\n");
			printf("The pizza is bacon supreme \r\n");
			break;
		}
		case thursday:
		{
			printf("The real day is Thursday \r\n");
			printf("The pizza is beef supreme \r\n");
			break;
		}
		case friday:
		{
			printf("The real day is Friday \r\n");
			printf("The pizza is meat ball supreme \r\n");
			break;
		}
		case saturday:
		{
			printf("The real day is Saturday \r\n");
			printf("The pizza is oreintal supreme \r\n");
			break;
		}
		default:
		{
			printf("The real day is Sunday \r\n");
			printf("The pizza is ham supreme \r\n");
			break;
		}
	}
	return 0;
}

int main ()
{
	enum days_of_the_week day;
	
	//day = random_get_day_of_week();
	//print_special(day);
	
	day = get_real_day_of_week();
	
	print_special(day);
	
	return 0;
}