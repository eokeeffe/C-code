/*Evan O'Keeffe
  10324289
  my getn function */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int mygetn(int a);
main()
{
	int a;
	printf("Please enter your numbers\r\n");
	scanf("%d",&a);
	mygetn(a);
}
int mygetn(int a)
{
	int digit,n,c;
	/*n=0;*/
	c=getchar();
	if(c!='\n')
	{
		digit=c-'0';
		n=digit;
		c=getchar();
		while(c!='\n')
		{
			c=getchar();
			digit=c-'0';
			n=(n*10)+digit;
		}
	}
	printf("%d\r\n",n);
	return(n);
}