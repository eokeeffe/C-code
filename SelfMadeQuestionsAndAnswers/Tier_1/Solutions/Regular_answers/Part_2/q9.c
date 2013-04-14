/*
	Tier 1 : Part 2	:	Question 9
*/
#include<stdio.h>

int main()
{
	float volume_of_a_cone , cone_radius , cone_height , Pi = 3.1415;
	
	printf("Please enter the cones radius \r\n");
	scanf("%f",&cone_radius);
	
	printf("Please enter the cones height \r\n");
	scanf("%f",&cone_height);
	
	volume_of_a_cone = (1/3) * Pi * ( cone_radius * cone_radius ) * cone_height;
	
	printf("The cones volume is %f \r\n",volume_of_a_cone);
	
	return 0;
}