/*moments equation(perpendicular)*/
#include<stdio.h>

void function()
{
	float torque,force,distance;
	printf("please enter the torque\r\n");
	scanf("%f",&torque);
	printf("please enter the perpendicular distance\r\r");
	scanf("%f",&distance);
	force=(torque*distance);
	printf("your answer is %f newtons\r\n",force);
}