/*evan o'keeffe 10324289
	25/09/2010
	Just playing around with the scanf 
	and printf and trying to see if I 
	can do anything useful with them*/
	
#include<stdio.h>

int main()
{
	float number1,number2,answer;
	
	printf("enter (number1) here \n");
	scanf("%f",&number1);
	printf("enter (number2) here \n");
	scanf("%f",&number2);
	answer= number1 + number2;
	
	printf("the answer is %.00f\r\n",answer);/*the added 0's before the %f means that the amount of zeros is limited to two*/
	return 0 ;
}