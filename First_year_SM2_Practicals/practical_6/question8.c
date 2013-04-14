/*Evan O'Keeffe
  10324289
  practical6 question8
*/
#include<stdio.h>
#define number 10
void main()
{
	int A[number],*p;
	printf("This program will re-arrange the array you input\r\n");
	
	
	for(p=A;p<(A+number);p++)
	{
		printf("Please enter value 10 numbers\r\n");
		scanf("%d",p);
	}
	printf("\n");
	
	for(p = ( A + number - 1 ); p >= A; --p )
	{
		printf("%d\r\n",*p);
	}
	
}