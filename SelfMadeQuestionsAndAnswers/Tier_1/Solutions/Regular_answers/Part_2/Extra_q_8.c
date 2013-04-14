/*
	Tier 1 : Part 2	: Extra	Question 8
*/
#include<stdio.h>
//This header file is needed for the sqrt function
#include<math.h> 


int main()
{
	float equation , x1 , x2 , y1 , y2 ;
	
	printf("Please enter the point for x1 \r\n");
	scanf("%d",&x1);
	
	printf("Please enter the point for x2 \r\n");
	scanf("%d",&x2);
	
	printf("Please enter the point for y1 \r\n");
	scanf("%d",&y1);
	
	printf("Please enter the point for y2 \r\n");
	scanf("%d",&y2);
	
	equation = sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) );
	
	printf("The Distance of the line = %d \r\n", equation );
	
	return 0;
}