#include <stdio.h>
#include <stdlib.h>

long long  int x;
long long  int n;

void power(long long  int x, long long  int n)
{
	long long  int result;
	long long  int i;
	
	result = x;
	result=result*result;
	//printf("result=%lld\r\n",result);
	for(i = 1; i < n-1; i++)
	{
		result *= x;
	}

	printf("result=%u\r\n",result);
}

int main()
{
	
	
	printf("Please enter your integer for the base\r\n");
	scanf("%lld",&x);
	printf("Please enter your integer for the power\r\n");
	scanf("%lld",&n);
	  
	power(x,n);

	return 0;
}






