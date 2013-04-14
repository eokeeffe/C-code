/*
	Tier 2 : Part 2	:	Question 1
	
	Global means the variables are held in a memory location accessible to all parts
	throughout the program and are accessible to all functions
	
	An auto or local variable is a variable which is defined within the scope of a function. 
	This sort of variables are also called automatic variables. 
	Automatic variables cannot retains it's value once the function returns. 
	That means the scope and life of an automatic variable is within the function it's defined in. 
	
	auto variables are _not_ initialized by the compiler (as pr the C standard). 
	if they are not initialized by the programmer they contain (stack) garbage.
	It is highly recommanded practice to initialize an auto variable while defining it.
	
		
	Well a static variable which is defined inside a function is not destroyed 
	once the function returns and hence retains it value even after the function returns. 
	The scope of this sort of static variable is within the function.
	A static variable of this sort cannot be called from outside the function. 
	So it's scope is just inside the function body.
	But even if it's scope happens to be within the function it's life is throughout 
	the program execution which means that the variable still is in memory. 
	
	Excerpts from Vivek Bhadra
	
	http://knol.google.com/k/auto-static-and-global-variable-c-programming#
*/
#include<stdio.h>

int main()
{
	return 0;
}