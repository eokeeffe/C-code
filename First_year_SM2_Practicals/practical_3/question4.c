/*Evan OKeeffe
  103242810
  question 4 practical 3 */
  
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

 void main()
 {
	int day,month,year;
	char slash1,slash2;
	char* month_name;
	char* date;
	printf("Please enter your date here\r\n");
	printf("in this format please dd/mm/yy\r\n");
	scanf("%d/%d/%d",&day,&month,&year);
	//printf("day=%d, month= %d, year=%d\r\n",day,month,year);
	
	switch(month)
	{
		case 1	:{month_name="january";break;}
		case 2	:{month_name="febuary";break;}
		case 3	:{month_name="march";break;}
		case 4	:{month_name="april";break;}
		case 5	:{month_name="may";break;}
		case 6	:{month_name="june";break;}
		case 7	:{month_name="july";break;}
		case 8	:{month_name="autumn";break;}
		case 9	:{month_name="september";break;}
		case 10	:{month_name="october";break;}
		case 11	:{month_name="november";break;}
		case 12	:{month_name="december";break;}
		
		default	:{printf("the number for the month was too big\r\n");break;}
	}
	switch(day)
	{
		case 1	:{date="st";break;}
		case 2	:{date="nd";break;}
		case 3	:{date="rd";break;}
		case 4	:
		case 5	:
		case 6	:
		case 7	:
		case 8	:
		case 9	:
		case 10	:
		case 11	:
		case 12	:
		case 13	:
		case 14	:
		case 15	:
		case 16	:
		case 17	:
		case 18	:
		case 19	:
		case 20	:{date="th";break;}
		case 21	:{date="st";break;}
		case 22	:{date="nd";break;}
		case 23	:{date="rd";break;}
		case 24	:
		case 25	:
		case 26	:
		case 27	:
		case 28	:
		case 29	:
		case 30	:{date="th";break;}
		case 31	:{date="st";break;}
		
		default	:{printf("the number for the day was too big\r\n");break;}
	}
	
	printf("Dated is the %d%s day of %s %d\r\n",day,date,month_name,year);
	//printf("you made it\r\n");
}