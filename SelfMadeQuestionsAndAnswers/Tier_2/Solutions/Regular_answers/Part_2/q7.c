
/*
	Tier 2 : Part 2	:	Question 7
*/
#include<stdio.h>

int ch; // global scope , accesible to all functions

int main()
{
	
	return 0;
}

int count; // global but only accesible to the function after its declaration , 
		   // therefore not visible to the main

int fun1()
{

	extern int number; // external use , eg has file scope , once its declared its
					   // accesible to all other files looking to use it
	return 0;
}

int fun2()
{
	extern int ch; // external use , eg has file scope , once its declared its
					   // accesible to all other files looking to use it
				   // although its the same data type and identifier 
				   //it may in some cases be mistaken depending on compiler and platform
	return 0; 
}

int fun3()
{
	
	return 0;
}

