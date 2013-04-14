/*
	Tier 1 : Part 2	:	Question 7
*/
#include<stdio.h>

int main()
{
	float sphere_radius , Pi = 3.1415 , volume_of_a_sphere;
	
	printf("Please enter the radius of the sphere\r\n");
	scanf("%f",& sphere_radius);
	
	volume_of_a_sphere = (4/3) * Pi * (sphere_radius*sphere_radius*sphere_radius);
	
	printf("The volume of the sphere is %d \r\n",volume_of_a_sphere);
	
	return 0;
}