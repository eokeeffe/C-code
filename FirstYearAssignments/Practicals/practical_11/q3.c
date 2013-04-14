/*Evan O'Keeffe
  10324289 
  practical 11 question2
*/

//the statement takes the absolute value of x
//then says x is equal to x if greater than 0
//else if x=xmin else x=-xmin

#include<stdio.h>

int main()
{
	int x,xmin;
	printf("formula= if(abs(x)<xmin) then x=(x>0)?xmin:-xmin\r\n");
	printf("please enter for x\r\n");
	scanf("%d",&x);
	printf("please enter for xmin\r\n");
	scanf("%d",&xmin);
	
	if(abs(x)<xmin){ x=(x>0)?xmin:-xmin;}//if the absolute value of x is less than xmin
										//then x=x as long as its greater than zero
										//or else x=xmin or else x=-xmin
	
	printf("x=%d\r\n",x);
	return 0;
}