/*Evan O'Keeffe
  10324289
  question6 practical4*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void pb(int n);
int n;

void main()
{
	printf("enter your value here please\r\n");
	scanf("%d",&n);
	pb(n);
	
}
void pb(int n)
{
	if(n!=0)
		{
			pb(n/2);
			putchar('0'+n%2);
		}
}
/*so the number inputed is checked for being zero 
  then it goes through the pb funtion again recursively
  passing the user's number over 2 into the next function
  then putchar displyas a the number n remainder to 2 +0*/
  