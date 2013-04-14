/*Evan O'Keeffe
  10324289
  question1 practical4*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int polynom(int number);
int answer;
int number;
void main()
{	
	printf("Please enter the number you want to go through the polynomial\r\n");
	scanf("%d",&number);
	polynom(number);
	printf("your answer is %d \r\n",answer);
}
int polynom(int number)
{
	answer=3*pow(number,5)+2*pow(number,4)-5*pow(number,3)-pow(number,2)+7*(number)-6;
	return answer;
}