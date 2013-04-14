/*
	Tier 1 : Part 7	:	Question 6
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int x = 0 , xmin;
	
	printf("The expression is this if(abs(x)< xmin){ x = (x>0)?xmin:-xmin;}\r\n");
	
	//	if(abs(x)< xmin){ x = (x>0)?xmin:-xmin;}
	//		|					|		|	
	//		|					|		|
	//		|					|		or else then x = -xmin
	//		|					|
	//		|					if x > 0 then x = xmin
	//		|
	//		if this statement is true then carry out this block instruction
	return 0;
}