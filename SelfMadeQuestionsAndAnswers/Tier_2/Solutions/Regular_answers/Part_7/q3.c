/*
	Tier 2 : Part 7	:	Question 3
	
	If the compiler complains about redefining the constant 
	dont worry , the math.h files constant hasn't changed
	only the constant you use in your file has changed
*/
#include<stdio.h>
#include<string.h>
#include<math.h>


int main()
{
	char change[100];
	
	printf("Pi = %f in math.h\r\n",M_PI); 
	
	#ifdef M_PI
		#undef M_PI
		#define M_PI 3.14
		strcpy(change,"Changed by the user");
	#else
		#undef M_PI
		#define M_PI 3.14
		strcpy(change,"Changed by the user with no compiler present");
	#endif

	printf("Pi = %f in math.h was %s\r\n",M_PI,change);
	
	return 0;
}