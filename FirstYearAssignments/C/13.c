/*Evan o'keeffe 10324289
  28/09/2010
  WAP, this reads the base ,height and produces a triangles area
*/
#include<stdio.h>

int main()
{
	int base,height,area;
	
	printf("please input (base) \r\n");
	scanf("%d",&base);
	printf("please input the (height) now \r\n");
	scanf("%d",&height);
	area = height*base ;
	
	printf("the base%d and height%d is area%d",base,height,area);
	
	return 0;
}