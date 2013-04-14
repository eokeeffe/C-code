/*
	Tier 1 : Part 7	:	Question 7
	
	Its the quadratic equation roots formula
	
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	float x1,x2;
	float A=2.0,B=4.0,C=2.0;
	
	x1=( ((-B)+(sqrt((B*B)-(4*A*C)))/(2*A)) );

    x2=( ((-B)-(sqrt((B*B)-(4*A*C)))/(2*A)) );
	
	printf("The 2 roots of the equation\r\n");
	printf(" %1.fx^2 %1.fx %1.f\r\n",A,B,C);
	printf("are (x %f) and (x %f) \r\n",x1,x2);
	
	return 0;
}