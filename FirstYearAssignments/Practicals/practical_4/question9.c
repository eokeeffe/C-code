/*Evan O'Keeffe
  10324289
  question 9 practical 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

void largest(int A,int n);
void average(int A,int n);
void positive(int A,int n);

void main()
{
	int n,a;
	int A[n]={1,3,5,67,54,-1,-19,-54,0};
	char answer[100];
	while(a<100){answer[a]='\0';a++;}
	a=0;
	
	printf("Please enter the size of the A\r\n");
	printf("if you want all the functions to work please enter 9\r\n");
	scanf("%d",&n);
	
	largest(A,n);
	average(A,n);
	positive(A,n);
}
void largest(int A,int n)
{
	/*int a=0;
	while(A[a]!='\0')
	{
		
	}*/
	
}
void average(int A,int n)
{
	int a=0,sum;
	while(A[a]!='\0')
	{
	
		sum=A[a]/a;
		a++;
	}
	printf("Average=%d\r\n",sum);
}
void positive(int A,int n)
{
	
}