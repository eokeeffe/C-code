/*Evan o'Keeffe
 10324289
 this program takes the users inputs 
 for a circle and 
 passes them to another function*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
float square(void);
float triangle(void);
float circle(void);
main()
{	int i;
	char e[100],f[100],g[100];
	i=0;
	printf("is it the area of a square,triangle or circle\r\n");
	gets(e);
	
	if(e[i]=='s'){square();exit(0);}
	if(e[i]=='t'){triangle();exit(0);}
	if(e[i]=='c'){circle();exit(0);}
}
float square(void)
{
	int i;
	float a,b,c,d,he,di,rad,crad,area;
	char e[100],f[100],g[100];
	
	printf("please enter the four corners\r\n");
	scanf("%f%f%f%f",&a,&b,&c,&d);
	area=(a)*(b)*(c)*(d);
	printf("area=%f\r\n",area);
}
float triangle(void)
{
	int i;
	float a,b,c,d,he,di,rad,crad,area;
	char e[100],f[100],g[100];
	
	printf("please enter your height\r\n");
	scanf("%f",&he);
	printf("please enter your diameter\r\n");
	scanf("%f",&di);
	area=(((1*di)/2)*he);
	printf("area=%f\r\n",area);
}
float circle(void)
{
	int i;
	float a,b,c,he,di,rad,crad,area;
	char e[100],f[100],g[100];
	i=0;
	printf("Do you have the radius or the diameter?\r\n");
	gets(f);
	if(f[i]=='r')
	{
	printf("please neter the radius\r\n"); 
	scanf("%f",&rad);
	area=((22/7)*(rad)*(rad));
	}
	if(f[i]=='d')
	{
	printf("please enter the diameter\r\n");
	scanf("%f",&crad);
	
	area=((22/7)*((1/2)*((crad)*(crad))));
	}
	printf("area=%f\r\n",area);
}