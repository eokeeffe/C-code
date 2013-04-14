/*
	Tier 1 : Part 7	:	Question 9
	
	The function on who to calculate Coulombic force between two charges
	
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double coulomb(double Q1,double Q2,double d);

int main()
{
	double charge_one =20.0, charge_two =20.0,distance_between_charges =1.5;
	printf("%lf is the coulombic force\r\nbetween charge one and charge two \r\n",coulomb(charge_one,charge_two,distance_between_charges) );
	
	return 0;
}

double coulomb(double Q1,double Q2,double d)
{
	double answer;
	double left,right;
	left=( 1/((4*22/7)*(pow(8.854,-12))) );
	right= (Q1*Q2)/(d*d);
	
	return answer=( right * left );
}