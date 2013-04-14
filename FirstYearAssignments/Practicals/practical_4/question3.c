/*Evan O'Keeffe
  10324289
  question3 practical4*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<tgmath.h>

unsigned int factorN(unsigned int number);
unsigned int factorial(unsigned int number );
unsigned int prime_check(unsigned int number);
unsigned int factor;
unsigned int number;

void main()
{
	
	printf("Please enter the you want to check\r\n");
	scanf("%d",&number);
	if(number>3)
	{
		prime_check(number);
		if(prime_check(number)==1){printf("The number is a prime\r\n");}
		else
			{printf("Number is not a prime\r\n");}
	}
	
	else 
		{printf("Zero cannot be used here\r\n");printf("1,2,3 are all primes\r\n");}
}
unsigned int prime_check(unsigned int number)
{
	unsigned int b=0,c;
	//printf("%d\n",number);
	
	for(c=2;c<number;c++)
	{
		//printf("%d\r\n",c);
		if((number % c) == 0){return 0;}
		else
			{b++;}
	}
	return 1;
}
/*int factorN(int number)
{
	factor=(factorial(number-1)+1)/number;
	return factor;
}
int factorial( int number )
{
    if ( number <= 1 )
        return 1;
    else
        return  number * factorial( number-1 );
}*/