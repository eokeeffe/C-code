/*
	Tier 2 : Part 3	:	Question 6
	
	The programmer here can either use the strcmp function here
	or they can use there own strcmp function from earlier 
*/
#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	if(strcmp(argv[1],argv[2])==0)
	{
		printf("%s and %s are the same \r\n",argv[1],argv[2]);
	}
	else
		{
			printf("%s and %s aren't the same \r\n",argv[1],argv[2]);
		}
	return 0;
}