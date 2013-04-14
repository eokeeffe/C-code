/*Evan o'Keeffe
 10324289
 this program reads from a file the GPA's of six people
 then displays their names and grades */
 /*this program hasnt been finished*/
#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

main()
{
	FILE *fopen(),*fp;
	char fn[100],z[100],name[100];
	char c;
	int  i=0,d=0,e=0,f=0,h=0,t=0;
	float a=4.0,b=3.4,g=2.8,p=2.2,j=1.6,k=1.0;
	float numa,numb,numc,numd,nume,numf,avg;
	
	
	printf("please enter the filename that the program will read to\r\n");
	gets(fn);
	fp=fopen(fn,"r");
	
	
	if(fp==NULL){printf("that file doesn't exist\r\nor is the wrong one\r\n");}
	 
	 c=getc(fp);
	 printf("%s\r\n",c);
	 while(c!=EOF)
	 {
		c=getc(fp);
		while(c==' ')
		{
		if(c=='a'||c=='A')
		{i++;}
		if(c=='b'||c=='B')
		{t++;}
		if(c=='c'||c=='C')
		{d++;}
		if(c=='d'||c=='D')
		{e++;}
		if(c=='e'||c=='E')
		{f++;}
		if(c=='f'||c=='F')
		{h++;}
		}
	 }
	  fclose(fp);
	  
	 fp=fopen(fn,"r");
	 c=getc(fp);
	 /*printf("%s\r\n",c);*/
	 while(c!=EOF)
	 {
		c=getc(fp);
		if(c!='\n')
		{scanf("%s",&name);}
	 }
	  
	 printf("you have %d a's\r\n",i);
	 printf("you have %d b's\r\n",t);
	 printf("you have %d c's\r\n",d);
	 printf("you have %d d's\r\n",e);
	 printf("you have %d e's\r\n",f);
	 printf("you have %d f's\r\n",h);	/*DEBUG FEATURE*/
	 
	 numa=(i*a);
	 numb=(t*b);
	 numc=(d*g);
	 numd=(e*p);
	 nume=(f*j);
	 numf=(h*k);
	 avg=(((numa)+(numb)+(numc)+(numd)+(nume)+(numf))/6.0);
	 
	 printf("%s \r\n",name);
	 printf("you Gpa is %f \r\n",avg);
	 
	 return 0;
}	