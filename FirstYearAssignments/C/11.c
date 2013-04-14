/*trying to solve a maths problems*/
#include<stdio.h>
#include<mat1.h>

int number1,number2,number3,answer,answer1;

int main()
{
	
	
	printf("input1 here (number1)  ");
	scanf("%4d",&number1);
	printf("\r\ninput2 here (number2)  ");
	scanf("%4d",&number2);
	printf("\r\ninput3 here (number3)  ");
	scanf("%4d",&number3);
	
	answer = (number1+number2)/number3;
	
	printf("the answer is %d\r\a\n",answer); 
	
	answer1=evan(number1,number2,number3);
	
	printf("the answer1 is %d\r\a\n",answer1);
	
}
dec evan(a,b,c)
{
	/*if(c=0){c=1;}*/
	printf("\r\n a=%4d,b=%4d,c=%4d \r\n",a,b,c);
	
	return (a+b)/c;
}
