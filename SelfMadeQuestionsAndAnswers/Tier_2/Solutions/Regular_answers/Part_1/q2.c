/*
	Tier 2 : Part 1	:	Question 2
	
*/
#include<stdio.h>

int main()
{
	int user_input;
	printf("This time we use the scanf to get the number\r\n");
	printf("Directly from the stdin file stream \r\n");
	
	while(fscanf(stdin,"%d",&user_input)!=1)
	{
		fflush(stdin);
	}
	
	printf("%d is what you entered\r\n",user_input);
	
	return 0;
}