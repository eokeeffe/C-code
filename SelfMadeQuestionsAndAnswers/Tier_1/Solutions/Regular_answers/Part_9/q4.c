/*
	Tier 1 : Part 9	:	Question 4
	
*/
#include<stdio.h>

double newton_root(double user_number_to_be_rooted);

int main()
{
	double user_number_to_be_rooted=0.0;
	
	printf("Please enter the number for the root\r\nDouble value please\r\n");
	scanf("%lf",&user_number_to_be_rooted);
	
	printf("%lf is the answer\r\n",newton_root(user_number_to_be_rooted));
	return 0;
}

double newton_root(double user_number_to_be_rooted)
{
	double variable_1=1,variable_2=0;
	int accuracy_of_the_root = 10;
	int count;


	for(count=0;count< accuracy_of_the_root;count++)
	{
		variable_2 = (.5) * ( variable_1 + ( user_number_to_be_rooted / variable_1) );
		variable_1 = variable_2;
	}
	
	
	return variable_2;
}