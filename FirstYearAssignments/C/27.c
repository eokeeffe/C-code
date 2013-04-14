/*Evan o@keeffe 10324289 
	28/09/2010
	Euro to sterling converter
*/
#include<stdio.h>

main()
{
	float sterling,euro,answer;
	
	printf("please enter the amount in euro \r\n");
	scanf("%f",&euro);
	
	answer = ((euro)/0.85);
	
	printf("The conversion is completed, the answer is %f\a\r\n",answer);
	
	return 0;
}