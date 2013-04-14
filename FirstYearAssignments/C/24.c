/*equation for force of a coulombic charge*/
#include<stdio.h>
void function()
{
	float v,q,f;
	printf("please enter the charge q\r\n");
	scanf("%f",&q);
	printf("please enter the voltage v\r\n");
	scanf("%f",&v);
	f=(q/v);
	printf("the answer is %f coulombs\r\n",f);
}