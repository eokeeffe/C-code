/*force of gravity equation*/
#include<stdio.h>
#include<math.h>
void function()
{
	float mass1,mass2,distance;
	float distancesquared,universalgravityconstant,force,answer;
	float line1,line2,e;
	
	printf("please enter the mass1\r\n");
	scanf("%f",&mass1);
	printf("please enter the mass2\r\n");
	scanf("%f",&mass2);
	printf("please enter the distance between the two bodies\r\n");
	scanf("%f",&distance);
	
	distancesquared=(distance*distance);
	universalgravityconstant=(6.67300);
	e=pow(10, -11);
	line1=(universalgravityconstant*e*mass1*mass2);
	line2=(distancesquared);
	answer=(line1/line2);
	
	printf("the answer is %fnewtons\r\n",answer);
}