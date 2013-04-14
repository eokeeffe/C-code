/*
	Tier 2 : Part 1	:	Question 1
	
*/
#include<stdio.h>


int main()
{
	int user_input=0;
	printf("Go on try to break this scanf now \r\n");
	printf("Takes an int \r\n");
	
	while(scanf("%d",&user_input)!=1) // the return value for each of the accepted parameters 
	{								  // is the number of parameters accpeted 
									  //in this case 1
		fflush(stdin);	// this function may be despised by the general programming 
						//community but sadly is the only way really to safely use
						//scanf 
						//What it does is clear EVERYTHING from  the stdin buffer ,
						//sadly this means that when dealing with files , entire 
						//files can be wiped out without a trace 
						//so use this very carefully
	}
	
	printf("%d is what you entered\r\n",user_input);
	
	return 0;
}