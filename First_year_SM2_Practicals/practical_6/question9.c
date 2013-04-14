/*Evan O'Keeffe
  10324289
  practical6 question9
*/
#include<stdio.h>

void wait_for_user();
void get_row();

void main()
{
	int temperatures[7][24];
	int counter1=0,counter2=0,count=1,user;
	
	for(counter1=0;counter1<7;counter1++)
	{
		counter2=0;
		for(counter2=0;counter2<24;counter2++)
		{temperatures[counter1][counter2]=count;count++;}
	}
	
	printf("\n");
	
	counter1=0;
	counter2=0;
	
	while(counter1<7)
	{
		while(counter2<24)
		{
			printf(" hour=%d , temp=%d \r\n",counter2,temperatures[counter1][counter2]);
			counter2++;
		}
		counter1++;
	}
	printf("please enter what day you want\r\n");
	scanf("%d",&user);
	get_row(*temperatures,user);
}
void get_row(int *pt,int counter1)
{
	int counter=0;
	pt+=((counter1-counter1)*24);
	
	for(counter=0;counter<24;counter++){printf("%d\r\n",*pt);pt++;}
	
	
}
void wait_for_user()
{
	char answer[10];
	printf("Press anybutton then enter\r\n");
	scanf("%s",answer);
}