/*Evan O'Keeffe
  10324289
  question 2 practical 3 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void squareroot(double user_number);	//used for checking the result of the newton function
void newton(double user_number);		//this is the newton square root function

main()
{
	double user_number;
	printf("Please enter the number you want the square root of\r\n");
	scanf("%lf",&user_number);
	
	//squareroot(user_number);
	newton(user_number);
	
}

void squareroot(double user_number)
{
	double checksum;
	checksum=sqrt(user_number);
	printf("the math.h function returns %g\r\n",checksum);
}
void newton(double user_number)
{
	double guess=10;
	double first,second=1;
	int i;
	
	
	for(i=0;i<10;i++)
	{
		second=(.5)*(first+(user_number/first));
		first=second;
	}
	printf("Your answer is %lf from my function\r\n",second);
}