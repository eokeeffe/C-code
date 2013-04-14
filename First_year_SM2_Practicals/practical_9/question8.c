/*Evan O'Keeffe
  10324289
  practical9 question6
*/
#include<stdio.h>
#include<math.h>

void main()
{
	int i,j;
    long ix ;
	unsigned u;
	float x;
	double dx;
	char c;
	
	
	printf("please enter for i\r\n");
	scanf("%d",&i);
	printf("please enter for j\r\n");
	scanf("%d",&j);
	printf("please enter for ix\r\n");
	scanf("%ld",&ix);
	printf("please enter for u\r\n");
	scanf("%u",&u);
	printf("please enter for x\r\n");
	scanf("%f",&x);
	printf("please enter for dx\r\n");
	scanf("%lf",&dx);
	printf("please enter for c\r\n");
	scanf("%c",&c);
	
	//part a 
	printf("i=%4d, j=%4d, x=%14.8e, dx=%14.8e\r\n",i,j,x,dx);
	
	//part b
	printf("i=%4d\r\n",i);
	printf("j=%4d\r\n",j);
	printf("x=%14.8e\r\n",x);
	printf("dx=%14.8e\r\n",dx);
	
	
	//part c
	printf("i=%5d\r\n",i);
	printf("ix=%12ld\r\n",ix);
	printf("j=%5d\r\n",j);
	printf("x=%10f\r\n",x);
	printf("u=%5d\r\n",u);
	
	//part d
	printf("i=%5d,ix=%12ld,ix=%12ld,j=%5d,j=%5d\r\n",i,ix,j);
	printf("x=%10f,u=%5d\r\n",x,u);
	
	//part e
	printf("i=%6d , u=%6d , c=%c\r\n",i,u,c);
	
	//part f
	printf("j=%d\r\n",j);
	printf("u=%u\r\n",u);
	printf("x=%f\r\n",x);
	
	//part g
	printf("j=%-d\r\n",j);
	printf("u=%-u\r\n",u);
	printf("x=%-f\r\n",x);
	
	//part h
	printf("j=%+d\r\n",j);
	printf("u=%-u\r\n",u);
	printf("x=%+f\r\n",x);
	
	//part i
	printf("j=%0d\r\n",j);
	printf("u=%0u\r\n",u);
	printf("x=%0f\r\n",x);
	
	//part j
	printf("j=%d\r\n",j);
	printf("u=%u\r\n",u);
	printf("x=%#f\r\n",x);
	
}