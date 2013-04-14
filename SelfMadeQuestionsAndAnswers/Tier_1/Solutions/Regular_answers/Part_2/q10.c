/*
	Tier 1 : Part 2	:	Question 10
*/
#include<stdio.h>

int main()
{
	float mass , speed_of_light = 299792458 , energy_in_joules;
	
	printf("Please enter the mass in Kilograms \r\n");
	scanf("%f",&mass);
	
	energy_in_joules = mass * ( speed_of_light * speed_of_light );
	
	printf("The enery released is %f \r\n", energy_in_joules );
	
	return 0;
}