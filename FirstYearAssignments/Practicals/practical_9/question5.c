/*Evan O'Keeffe
  10324289
  practical9 question5
*/
#include<stdio.h>
#include<math.h>

void main()
{
	int i,j,k,d;
	float c,e;
	
	printf("Please enter for int i\r\n");
	scanf("%d",&i);
	printf("Please enter for int j\r\n");
	scanf("%d",&j);
	printf("Please enter for int i\r\n");
	scanf("%d",&k);
	
	//part a
	printf("i=%3d\r\n",i);
	printf("j=%3d\r\n",j);
	printf("k=%3d\r\n",k);
	
	//part b
	printf("i+j=%5d\r\n",(i+j));
	printf("i-k=%5d\r\n",(i-k));
	
	//part c
	d = sqrt(i+j);
	c = sqrt(i+j);
	e = abs(i-k);
	
	printf("int of square-root(i+j)=%9d\r\n",d);
	printf("float of square-root(i+j)=%9f\r\n",c);
	printf("int absolute value(i-k)=%7d\r\n",abs(i-k));
	//printf("float absolute value(i-k)=%7f\r\n",e);
}

