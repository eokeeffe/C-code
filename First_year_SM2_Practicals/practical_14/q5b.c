/* Evan O'Keeffe
   10324289
   practical 14 question5 part a
*/
#include<stdio.h>

double funct1( double a , double b);
static double funct2(double a, double b);

void main()
{
	double x , y, z;

 z = funct1 ( x , y);

}
double funct1( double a , double b)
{
	double c ;
	c = funct2(a , b ) ;
}
static double funct2(double a, double b)
{
	return (a+b);
}