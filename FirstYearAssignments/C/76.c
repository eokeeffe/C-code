/*Evan O'Keeffe
  10324289
  my putn function */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int myputn(int a);
main()
{	
	int a;
	printf("Please enter your digits \r\n");
	scanf("%d",&a);
	myputn(a);
	exit(0);
}
int myputn(int a)
{
	int i,div,rem,num[100],number;
	i=0;
	
	div=number/10;
	rem=number%10;
	while(div!=0)
	{
		num[i]=rem+'0';
		i=i+1;
		number=div;
		div=number/10;
		rem=number%10;
	}
	num[i]=rem+'0';
	while(i>=0)
	{
		putchar(num[i]);
		i=i-1;
	}
}