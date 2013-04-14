/*Evan O'Keeffe
  10324289
  practical 12 question 5
*/
#include<stdio.h>
#include<string.h>

#define N 10
#define INC(x) x+1
#define SUB(x,y) x-y
#define SQR(x) ((x)*(x))
#define CUBE(x)(SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

//changed M2 , #x#y to #x #y

int main(void)
{
	int a[N],i,x,y,m,xy;
	//changed all j,k with x,y
	#ifdef N 

	i=x;
	
	#else
	
	x=i;
	
	#endif
	
	i=10*INC(x);
	
	i=SUB(x,y);
	
	i= SQR( SQR(x) );
	
	i= CUBE(x);
	
	i= M1(x,y);
	
	puts(M2(i,x));
	
	#undef SQR
	//i = SQR(x); //this creates a compile time error
	
	#define SQR i=SQR(x);
	
	return 0;
}