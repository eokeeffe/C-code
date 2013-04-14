/*Evan O'keeffe
  10324289
  practical17 question2
*/
#include<stdio.h>


int i,year;
int print_table(int year,float* investment)
{
	int a,i,j;
	for(i=0,j=0,a=0;j<year;i++,j++)
	{
		if((i%12)==0){printf("Year:%d amount:%f \r\n",a,investment[i]);a++;}//so if i is directly divisible by 12 then print the statement
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
	year=year*12;
	printf("Please enter the investment\r\n");
	scanf("%f%*c",&invest);
	
	float investment[year];
	temp2=invest;
	for(i=0;i<year;i++)
	{
		temp0=0;
		temp1=0;
		temp0=invest/rate;
		//printf("incre:%f\r\n",temp0);
		temp1=invest+temp0;
		temp2 += temp0;	
		//printf("current invest: %f\r\n",temp2);
		
		investment[i]=temp2;
		//printf("invest = %f\r\n",investment[i]);
	}
	print_table(year,investment);
	return 0;
}