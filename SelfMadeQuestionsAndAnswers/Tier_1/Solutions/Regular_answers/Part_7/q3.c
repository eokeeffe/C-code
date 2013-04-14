/*
	Tier 1 : Part 7	:	Question 3
	
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=5,b=10;
	printf(" a= %d and B=%d \r\n",a,b);
	//	a*=b is the same as a= a*b which simply multiplies
 	//	a/=b is the same as a= a/b which simply divides
	//	a&=b is the same as a=a&b 
	printf("An example for a=a&b is %d\r\n",a&=b);
	//	a%=b is the same as a=a%b which simply gets the remainder of the divison of a by b
	printf("An example for a=a%b is %d\r\n",(a%=b));
	//	a^=b is the same as a=a^b is the exclusive version of the a|=b and returns B in this case
	printf("An example for a=a^b is %d\r\n",a^=b);
	//	a|=b is the same as a= a|b , computes the logical OR on a and b and return B in this case
	printf("An example for a|=b is %d\r\n",a|=b);
	//	a<<=b is the same as a= a<<b , shifts bits to the right
	printf("An example for a<<=b is %d\r\n",a<<=b);
	//	a>>=b is the same as a = a>>b , shifts bits to the left
	printf("An example for a>>b is %d\r\n",a>>=b);
	
	return 0;
}