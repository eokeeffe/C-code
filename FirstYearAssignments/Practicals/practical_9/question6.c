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
	printf("x=%8.4f\r\n",x);
	printf("y=%8.4f\r\n",y);
	printf("z=%8.4f\r\n",z);
	
	//part b
	printf("x+y=%9.3f\r\n",(x+y));
	printf("x-z=%9.3f\r\n",(x-z));
	
	//part c
	printf("float of square-root(x+y)=%12.4f\r\n",sqrt(x+y));
	printf("float absolute value(x-z)=%10.4f\r\n",abs(x-z));
	
	
}