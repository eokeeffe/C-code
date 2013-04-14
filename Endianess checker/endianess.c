/*
	program to find the endianess of a machine
*/
#include<stdio.h>

int main()
{
	int x = 1;
	if(*(char *)&x == 1)
	{
		printf("little-endian\n");
	}
	else
	{	
		printf("big-endian\n");
	}
	
	return 0;
}