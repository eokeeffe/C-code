/*force of centripetal acceleration*/
#include<stdio.h>
void function()
{
	float mass,v,vsquared,r,answer;
	float line1,line2;
	
	printf("please input the mass\r\n");
	scanf("%f",&mass);
	printf("please input the 'v' value\r\n");
	scanf("%f",&v);
	printf("please input the 'r' value\r\n");
	scanf("%f",&r);
	
	vsquared=(v*v);
	line1=(mass*vsquared);
	line2=(r);
	answer=(line1/line2);
	
	printf("the answer is %f newtons\r\n",answer);
}