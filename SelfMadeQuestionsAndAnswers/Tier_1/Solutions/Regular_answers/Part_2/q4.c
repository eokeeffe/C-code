/*
	Tier 1 : Part 2	:	Question 4
*/
#include<stdio.h>

int main()
{
	int radius ;
	float Pi = 3.1415 , area_of_the_circle;
	
	printf("Please enter a length of the square \r\n");
	scanf("%d",&radius);
	
	area_of_the_circle = Pi * ( radius * radius );
	
	printf("The area of the circle is %f \r\n", area_of_the_circle );
	
	return 0;
}