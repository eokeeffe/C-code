/*
	Tier 1 : Part 2	: Extra	Question 6
*/
#include<stdio.h>

int main()
{
	float triangle_base , perpendicular_height , triangle_area ;
	
	printf("Please enter the length of the base of the triangle \r\n");
	scanf("%f",&triangle_base);
	
	printf("Please enter the perpendicular height of the triangle \r\n");
	scanf("%f",&perpendicular_height);
	
	triangle_area = (.5) * triangle_base * perpendicular_height;
	
	printf("The Area of the triangle is = %f \r\n",triangle_area);
	
	return 0;
}