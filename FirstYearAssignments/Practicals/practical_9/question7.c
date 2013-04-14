/*Evan O'Keeffe
  10324289
  practical9 question6
*/
#include<stdio.h>
#include<math.h>

void main()
{
	float x,y,z;
	
	printf("Please enter for int x\r\n");
	scanf("%f",&x);
	printf("Please enter for int y\r\n");
	scanf("%f",&y);
	printf("Please enter for int z\r\n");
	scanf("%f",&z);
	
	//part a
	printf("x=%12.4e\r\n",x);
	printf("y=%12.4e\r\n",y);
	printf("z=%12.4e\r\n",z);
	
	//part b
	printf("x+y=%14.5e\r\n",(x+y));
	printf("x-z=%14.5e\r\n",(x-z));
	
	//part c
	printf("float-e-notaion of square-root(x+y)=%12.7e\r\n",sqrt(x+y));
	printf("float-e-notaion absolute value(x-z)=%15.7f\r\n",abs(x-z));
	
}