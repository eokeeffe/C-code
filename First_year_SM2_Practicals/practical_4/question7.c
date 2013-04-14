/*Evan O'Keeffe
  10324289
  question 7 practical 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int day_of_year(int month,int day,int year);
int month,day,year;
void main()
{
	printf("Please enter the month here\r\n");
	scanf("%d",&month);
	
	if(month<1||month>12){printf("Please try again\r\n");main();}
	printf("Please enter the day here please\r\n");
	scanf("%d",&day);
	
	if(day<1||day>31){printf("Please try again\r\n");main();}
	
	else if((month==4&&day<30)||(day>28&&month==2)||(month==6&&day<30)||(month==9&&day<30)||(month==10&&day<30))
		{printf("Please try again\r\n");main();}
		
	printf("Please enter the year here\r\n");
	scanf("%d",&year);
	
	printf("\n%d\r\n",day_of_year(month,day,year));
}
int day_of_year(int month,int day,int year)
{
	//printf("%d month,%d day,%d year\r\n",month,day,year);
	if(year%4)
	{
			switch(month)
		{
			case 1:{day=day;return day;}
			case 2:{day=day+31;return day;}
			case 3:{day=day+60;return day;}
			case 4:{day=day+91;return day;}
			case 5:{day=day+121;return day;}
			case 6:{day=day+152;return day;}
			case 7:{day=day+182;return day;}
			case 8:{day=day+213;return day;}
			case 9:{day=day+244;return day;}
			case 10:{day=274;return day;}
			case 11:{day=304;return day;}
			default:{day=334;return day;}
		}
	}
		
	else
	{
		switch(month)
		{
			case 1:{day=day;return day;}
			case 2:{day=day+31;return day;}
			case 3:{day=day+59;return day;}
			case 4:{day=day+90;return day;}
			case 5:{day=day+120;return day;}
			case 6:{day=day+151;return day;}
			case 7:{day=day+181;return day;}
			case 8:{day=day+212;return day;}
			case 9:{day=day+243;return day;}
			case 10:{day=273;return day;}
			case 11:{day=303;return day;}
			default:{day=333;return day;}
		}
	}
	
}