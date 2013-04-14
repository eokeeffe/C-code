/*Evan O'Keeffe
  10324289 
  practical 11 question4
*/
#include<stdio.h>

unsigned int f(unsigned int i,int m,int n);

//this operation f returns the right adjusted n bit field of x
//that begins at position p

int main()
{
	unsigned int i,m,n;
	
	printf("please enter a value for i\r\n");
	scanf("%ud",&i);
	printf("please enter a value for m\r\n");
	scanf("%ud",&m);
	printf("please enter a value for n\r\n");
	scanf("%ud",&n);
	
	printf("\nresult = %u \r\n",f(i,m,n));
}

unsigned int f(unsigned int i,int m,int n)
{	
	return ( i >> (m+1-n)) &~ (~0<<n);	
	//i is adjusted to the right by m+1-n
	//and 0 is adjusted to the last bit at the end
	//in other words
	//this operation returns the right adjusted n bit field of x
	//that begins at position p
}