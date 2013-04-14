#include<stdio.h>
#include<math.h>
int main()
{
	int x=0,answer,user_input;
	
	while(user_input!=0)
	{
		printf("Please enter a number here\r\n");
		scanf("%d",&x);
		user_input=x;
		answer =( pow(x,5) - (2*3) + (2*2) - (3*x) + 12 );
		printf("x=%d  , after_function= %d\r\n",x,answer);
	}
	
	return 0;
}