/*conservation of momentum equation*/
#include<stdio.h>

void function()
{ 	
	float mass1,mass2,u1,u2,v,answer,line1,line2;
	printf("please enter the mass1\r\n");
	scanf("%f",&mass1);
	printf("please enter the value for mass2\r\n");
	scanf("%f",&mass2);
	printf("Please enter the initial velocity for body1(u1)\r\n");
	scanf("%f",&u1);
	printf("please enter the velocity for body2(u2)\r\n");
	scanf("%f",&u2);
	printf("please enter the final velocity(v)\r\n");
	scanf("%f",&v);
	
	line1=((mass1*u1)+(mass2*u2));
	line2=((mass1+mass2)*v);
	
	if (line1=line2){printf("the answer of line1%f and line2%f is true\r\n");}
		    
	if  (line1!=line2){printf("the answer of line1%f and line2%f is flase\r\n");}
}