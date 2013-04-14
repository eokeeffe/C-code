/*Evan O'Keeffe
  10324289 
  practical 11 question2
  this will take a number 3 digits long and give you the inverse of the number
*/
#include<stdio.h>

int main()
{
	int i,a,b,c;
	printf("please enter a 3 digit number \r\n");
	scanf("%3d",&i);//i is 3 digits long ONLY
	
	a=i%100;//a=remainder of i/100
	b=a%10;//b=remainder of a/10
	
	c = i;
	c = c-a;//c=c-(remainder of i/100)
	c=c/100;
	
	a -= b;//a=a-b
	a =a/10;
	
	printf("%d %d %d\r\n",a ,b ,c);//prints the inverse
	
	return 0;
}