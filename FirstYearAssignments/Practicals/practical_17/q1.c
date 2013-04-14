/*Evan O'keeffe
  10324289
  practical17 question1
*/
#include<stdio.h>

int i,year;
int print_table(int year,float* investment)//takes a float array and year
{
	int i;
	for(i=0;i<year;i++)
	{
		printf("Year:%d amount:%f \r\n",i,investment[i]);
	}
	return 0;
}
int main()
{
	float rate,invest,temp0,temp1,temp2;
	printf("Whats the interest rate?\r\n");
	scanf("%f%*c",&rate);
	
	printf("Whats the number of years?\r\n");
	scanf("%d%*c",&year);
	
	printf("Please enter the investment\r\n");
	scanf("%f%*c",&invest);
	
	float investment[year];
	temp2=invest;
	for(i=0;i<year;i++)
	{
		temp0=0;//reset the investment each year
		temp1=0;
		temp0=invest/rate;//standard investment
		//printf("incre:%f\r\n",temp0);
		temp1=invest+temp0;
		temp2 += temp0;	//increments the investment
		//printf("current invest: %f\r\n",temp2);
		
		investment[i]=temp2;
		//printf("invest = %f\r\n",investment[i]);
	}
	print_table(year,investment);
	return 0;
}