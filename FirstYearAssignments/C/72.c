/*Evan O'Keeffe
  10324289
  fibonaci sequence stuff
  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
void fib(int n);
main()
{	
	printf("how many terms do you want?\r\n");
	scanf("%d",&n);
	fib(n);
	exit(0);
}
void fib(n)
{
	int a=0,b=1,sum,i,m,even,prime;
	
	for(i=0;i<n;i++)
	{
		printf("%d\r\n",a);
		sum=a+b;
		a=b;
		b=sum;
	}
}