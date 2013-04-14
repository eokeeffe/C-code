/*Evan O'Keeffe
  10324289
  question4 practical4*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double median(double a,double b,double c);

int a,b,c;
double middle_man;

void main()
{
	printf("please enter number one:\n");
	scanf("%d",&a);
	printf("please enter number two:\n");
	scanf("%d",&b);
	printf("please enter number three:\n");
	scanf("%d",&c);
	median(a,b,c);
	printf("number 1 = %d\r\n",a);
	printf("number 1 = %d\r\n",b);
	printf("number 1 = %d\r\n",c);
	printf("number 1 = %lf\r\n",middle_man);
}
double median(double a,double b,double c)
{
	if(a<=b)
		{
			if(b<=c)
				{middle_man=b;}
		 else
		  {
			if(a<=c){middle_man=c;}
				else
					{middle_man=a;}
		   }
		 }
	if(c<=b){middle_man=b;}
	if(a<=c){middle_man=a;}
	else
		{middle_man=c;}
		
	return middle_man;
}

//mb version
