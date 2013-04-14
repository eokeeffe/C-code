/*evan o'keeffe 10324289
	24/09/2010
	This program converts the feet input into inces*/
	
#include<stdio.h>

int main()
{
	float feet,inches; /*try to space the functions logically ie try to group the terms so that it is neat*/
	
	printf("enter value in (feet) here\n"); /*the value entered here*/
	scanf("%f",&feet);						/*is read by the program here*/
	inches = feet * 12;						/*then the value is taken here and multiplied*/
	
	printf("the answer is %f\r\n",inches); /*the value is then input here*/ 
	return 0;
	
}
	