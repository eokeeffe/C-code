#include<stdio.h>
int max(int a,int b);

int main()
{
	double a[] = {1,5,3,2};
	double b[] = {4,3,7,1};
	int size1 = (sizeof(a)/sizeof(a[0]));
	int size2 = (sizeof(b)/sizeof(b[0]));
	int M = max(size1,size2);
	double c[M];
	int count=0;
	for(count=0;count<M;count++)
	{
	c[count] = a[count]*b[count];
	}
	printf("vector A:");
	for(count=0;count<size1;count++)
	{
	printf(" %lf ",a[count]);
	}
	printf("\r\nvector B:");
	for(count=0;count<size2;count++)
	{
	printf(" %lf ",b[count]);
	}
	printf("\r\nvector C:");
	for(count=0;count<M;count++)
	{
	printf(" %lf ",c[count]);
	}
	double  dot_product=0.0;
	printf("\r\n");
	for(count=0;count<M;count++)
	{
		dot_product+=c[count];
	}
	printf("\r\ndot product = %lf\r\n",dot_product);
	return 0;
}
int max(int a,int b)
{
	if( a > b)
	{
	return a;
	}
	if( b > a)
	{
	return b;
	}
}
