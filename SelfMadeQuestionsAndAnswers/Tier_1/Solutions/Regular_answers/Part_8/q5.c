/*
	Tier 1 : Part 8	:	Question 5
	Here the user must be able to see which assignements are completed first
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int numer_1 = 1,number_2 = 5,number_3 = 11 ,number_4 = 0;
	
	number_4 = ( (number_2)+=( number_2+ (number_3 *= numer_1-number_2) ));
//           |             |           |			|
//			 Fourth		   |		   |		    First(evaluated from the inner parenthesis)
//	Furthest assignement   |           Second as inside outer parenthesis
//						   |
//						   Third as its an assignement operator
//
//
//
//
//
	
	printf("the result =%d \r\n" , number_4 );
	
	return 0;
}