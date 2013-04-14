/*
	Tier 2 : Part 3	:	Question 3
*/
#include<stdio.h>

int main(int argc, char *argv[] )
{
	printf("argc=%d\r\n",argc);
	int loop_count;

	for(loop_count = 0; loop_count < argc; loop_count++)
	{
		printf("arguement: %d = %s\r\n", loop_count, argv[loop_count]);
	}
	
	return 0;
}