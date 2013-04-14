/*Evan O'Keeffe
  10324289
  program using the getn and putn that were previously made */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int mygetn(int a);
int myputn(int a);
main()
{	
	int a,i;
	printf("Please enter your digits \r\n");
	scanf("%d",&a);
	i=mygetn(a);
	printf("you entered:");
	myputn(i);
	exit(0);
}
int mygetn(int a)
{
	int digit,n,c;
	n=0;
	c=getchar();
	if(c!='\n')
	{
		digit=c-'0';
		n=digit;
		c=getchar();
		while(c!='\n')
		{
			n=(n*10)+digit;
			digit=c-'0';
			c=getchar();
		}
	}
	printf("%d\r\n",n);
	return(n);
}
void myputn(int a)
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