/*Evan o'Keeffe
  10324289
  Matrix solver for 2x2,3x3,4x4 matrix determinants */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

main()
{
	char choice;
	float a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
	float a1,a2,a3,b1,b2,b3,c1,c2,c3;
	float line1,line2,line3,line4,line5,line6,line7,line8,line9;
	float sum1,sum2,answer,mul,lti,ipl,ply,deta,detb,detc;
	
	printf("Which matrix is to be solved?\r\nthis will give determinants for all\r\n");
	printf("this wont give the inverse for all the matrixes\r\n");
	
	while(choice!='x'||choice!='y'||choice!='z'||choice=='\0'||choice=='\n')
	{
	printf("x for 2x2\r\n");
	printf("y for 3x3\r\n");
	printf("z for 4x4\r\n");/*(not finished yet)*/
	printf("please enter your choice\r\n");
	scanf("%c",&choice);
	
	/*if(){printf("please enter something next time\r\n");}*/
	
	if(choice=='x')
	{
	printf("a,b\r\n");
	printf("c,d\r\n");
	printf("please enter a value for a,b,c,d\r\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	deta=(a*d)-(b*c);
	printf("DET =%f\r\n\n",deta);
	mul=((1/deta)*a);
	lti=((1/deta)*b);
	ipl=((1/deta)*c);
	ply=((1/deta)*d);
	printf("%f,%f\r\n\n",mul,lti);
	printf("%f,%f\r\n\n",ipl,ply);
				 }
				 
	if(choice=='y')
	{
	printf("a,b,c\r\n");
	printf("d,e,f\r\n");
	printf("g,h,i\r\n");
	
	printf("please enter your values for the above\r\n");
	scanf("%f%f%f%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f,&g,&h,&i);
	
	detb=((a*e*i)+(b*f*g)+(c*d*h)-(a*f*h)-(b*d*i)-(c*e*g));
	printf("the det is %f\r\n",detb);
	
	a1=detb*a;
	a2=detb*b;
	a3=detb*c;
	b1=detb*d;
	b2=detb*e;
	b3=detb*f;
	c1=detb*g;
	c2=detb*h;
	c3=detb*i;
	
	printf("%f,%f,%f\r\n\n",a1,a2,a3);
	printf("%f,%f,%f\r\n\n",b1,b2,b3);
	printf("%f,%f,%f\r\n\n",c1,c2,c3);
				 }
	if(choice=='z')
	{
	printf("a,b,c,d\r\n");
	printf("d,e,f,g\r\n");
	printf("h,i,j,k\r\n");
	printf("l,m,n,o\r\n");
	
	printf("please enter your values across the way\r\n");
	scanf("%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n,&o,&p);
	
	line1=((a*f)-(e*b)+(i*b)-(m*b));/*a*/
	line2=((a*g)-(e*c)+(i*c)-(m*c));/*b*/
	line3=((a*h)-(e*d)+(i*d)-(m*d));/*c*/
	line4=((a*j)-(e*j)+(i*f)-(m*f));/*d*/
	line5=((a*h)-(e*k)+(i*g)-(m*g));/*e*/
	line6=((a*l)-(e*l)+(i*h)-(m*h));/*f*/
	line7=((a*n)-(e*n)+(i*n)-(m*j));/*g*/
	line8=((a*o)-(e*o)+(i*o)-(m*k));/*h*/
	line9=((a*p)-(e*p)+(i*p)-(m*l));/*i*/
	/*this part takes the 4x4 and simplifies into a 3x3 which then goes through the same*/
	/*steps as the 3x3 body*/
	
	sum1=((line1*line5*line9)+(line2*line6*line7)+(line3*line4*line8));
	sum2=((line1*line6*line8)+(line2*line4*line9)+(line3*line5*line7));
	answer=sum1-sum2;
	
	detc=answer;
	printf("your answer is %f\r\n\n",detc);
	printf("thank you\r\n");
	}
	printf("enter q to quit\r\n");
	scanf("%c",&q);
	if(choice=='q'){break;}
	
	}
	return 0;
}
	
	
	