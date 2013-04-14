/*Evan O'Keeffe
  10324289
  practical8 question4
*/
#include <stdio.h>
/*A.
typedef union 
{
	int i;
	float f ;
} udef;

void funct(udef u);

void main ( )
{
	udef u;
	u.i = 100;
	u.f = 0.5;
	funct ( u);
	printf("%d %f\n", u.i, u.f);
}
void funct(udef u)
{
	u.i = 200;
	printf("%d %f\n", u.i, u.f);
	return;
}*/

//the program first prints whats in the funct function which is 200 , the other value is 0 as it hasn't been defined
//then the second printf which is in the main will print the values of u.i and u.f which are going to return a erroronos number and .5000000000 
//the erroronos number as the numbers in the union will read sequantially , but the previous number will simply be mixed with the new number creating a weird answer

/*typedef union 
{
	int i;
	float f ;
} udef;

void funct(udef u);
main ( )
{
	udef u;
	u.i = 100;
	u.f = 0.5;
	funct ( u);
	printf("%d %f\n", u.i, u.f);
}
void funct(udef u)
{
	u.f = -0.3;
	printf("%d %f\n", u.i, u.f);
	return;
}*/

//this program like the last one will print the printf in the funct first with a weird number(not defined) then -0.3000000
//the second one will print will print a weird number as its been mixed with the next number , then 0.500000 as it was defined last

typedef union 
{
	int i;
	float f ;
} udef;

udef funct(udef u);

main ( )
{
	udef u;
	u.i = 100;
	u.f = 0.5;
	u = funct ( u);
	printf("%d %f\n", u.i, u.f);
}
udef funct(udef u)
{
	u.f = -0.3;
	printf("%d %f\n", u.i, u.f);
	return u;
}

//this program like the last one will print the printf in the funct first with a weird number(not defined) then -0.3000000 as it was last defined
//the second one will print will print a weird number as its been mixed with the next number which is a different type, -0.300 as the u was returned from funct then 
//the next value printed will also be -0.300 like the last one 