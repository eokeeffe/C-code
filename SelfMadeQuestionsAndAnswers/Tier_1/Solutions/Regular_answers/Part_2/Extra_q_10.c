/*
	Tier 1 : Part 2	: Extra	Question 10
*/
#include<stdio.h>
//this header file is need for the power function pow();
#include<math.h>

int main()
{
	//variables
	float distance_between_masses , Mass_1 , Mass_2 ;
	
	double universal_gravitation_constant , force_of_gravity;
	
	printf("Please enter the mass for the first object in Kilograms \r\n");
	scanf("%f",&Mass_1);
	
	printf("Please enter the mass for the second object in Kilograms \r\n");
	scanf("%f",&Mass_2);
	
	printf("Please enter the distance between the 2 objects in meters\r\n");
	scanf("%f",&distance_between_masses);
	
	universal_gravitation_constant = pow( (6.7*10) , (-11) );
	
	force_of_gravity = ( (Mass_1 * Mass_2) / (distance_between_masses*distance_between_masses));
	
	printf("The force of gravity is = %lf \r\n",force_of_gravity);
	
	return 0;
}