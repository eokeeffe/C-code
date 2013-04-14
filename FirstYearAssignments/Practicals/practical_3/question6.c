/*Evan OKeeffe
  103242810
  question 5 practical 3 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

char* get_month(int user_choice);
void create_chart(char* month);
int get_number(char* month);
char* month;
int a;

void main()
{
	int user_choice;
	printf("Please enter the month you want displayed\r\n");
	scanf("%d",&user_choice);
	get_month(user_choice);
	create_chart(month);
	
}
char* get_month(int user_choice)
{
	
	//printf("the number was %d\r\n",user_choice);
	
	switch(user_choice)
	{
		case 1	:{month="january";break;}
		case 2	:{month="febuary";break;}
		case 3	:{month="march";break;}
		case 4	:{month="april";break;}
		case 5	:{month="may";break;}
		case 6	:{month="june";break;}
		case 7	:{month="july";break;}
		case 8	:{month="autumn";break;}
		case 9	:{month="september";break;}
		case 10	:{month="october";break;}
		case 11	:{month="november";break;}
		case 12	:{month="december";break;}
		
		default	:{printf("the number for the month was too big\r\n");break;}
	}
	//printf(" the month is %s \r\n",month);
	return (month);
}
void create_chart(char* month)
{
	int i=0,j=0;
	get_number(month);
	//printf("%s\r\n",month);
	printf("Monday  Tuesday  Wensday  Thursday  Friday  Saturday  Sunday \n");
	printf("-------|--------|--------|---------|-------|--------|--------|\n\n");
	printf("__%d_______%d________%d_________%d__________%d________%d_______%d__ \n",  a ,  a+1 ,  a+2 ,  a+3 ,  a+4 ,  a+5 ,  a+6 );
	printf("-------|--------|--------|---------|-------|--------|--------|\n\n");
	printf("__%d________%d_______%d________%d________%d_______%d_______%d___ \n",  a+7 ,  a+8 ,  a+9 ,  a+10 ,  a+11 ,  a+12 ,  a+13 );
	printf("-------|--------|--------|---------|-------|--------|--------|\n\n");
	printf("__%d______%d_______%d________%d________%d_______%d_______%d___ \n",  a+14 ,  a+15 ,  a+16 ,  a+17 ,  a+18 ,  a+19 ,  a+20 );
	printf("-------|--------|--------|---------|-------|--------|--------|\n\n");
	printf("__%d______%d_______%d________%d________%d_______%d_______%d___ \n",  a+21 ,  a+22 ,  a+23 ,  a+24 ,  a+25 ,  a+26 ,  a+27 );

	printf("-------|--------|--------|---------|-------|--------|--------|\n\n");
	printf("__%d______%d_______%d________%d________%d_______%d_______%d___\n",a+28,a+29,a+30,a+31,a+32,a+33,a+34);
	printf("-------|--------|\n\n");
	printf("__%d______%d__\n",a+35,a+36);
	
}
int get_number(char* month)
{
	if(month=="january"){a=-6;}
	if(month=="febuary"){a=-2;}
	if(month=="march"){a=-2;}
	if(month=="april"){a=-5;}
	if(month=="may"){a=0;}
	if(month=="june"){a=-3;}
	if(month=="july"){a=-5;}
	if(month=="august"){a=-1;}
	if(month=="september"){a=-4;}
	if(month=="october"){a=-6;}
	if(month=="november"){a=-2;}
	if(month=="december"){a=-4;}
	return a;
}