/*Evan O'Keeffe
  10324289
  question2 practical4*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int check(int x,int y,int n);
int x,y,n;

void main()
{
	printf("enter x:\r\n");
	scanf("%d",&x);
	printf("enter y:\r\n");
	scanf("%d",&y);
	printf("enter n:\r\n");
	scanf("%d",&n);
	check(x,y,n);
	printf("\n%d\r\n",check(x,y,n));
}
int check(int x,int y,int n)
{
	if(n-1<x>0||n-1<y>0){return 1;}
	else
		{return 0;}
}
