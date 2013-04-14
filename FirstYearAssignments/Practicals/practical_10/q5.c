/*Evan O'Keeffe
  10324289
  question5 practical 10
*/

#define true 1
#define false 0
#define amount 20
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int check_file(FILE *fpt);	//checks if the file already exists
void write_to_file(char name[20]);
FILE *pt1,*fopen(),*pt2;


struct{
	int a;
	float b;
	char c;
	char name[amount];
}values;

void main()
{
	
	pt1=fopen("data.old.dat","r");
	
	if(check_file(pt1)==true)
	{
		fgets(values.name,amount,pt1);
		//printf("%s\r\n",values.name);
		fclose(pt1);
		write_to_file(values.name);
	}
	if(check_file(pt1)==false)
	{
		fclose(pt1);
		printf("file not there1\r\n");
		exit(0);
	}
}

void write_to_file(char name[20])
{
	pt2=fopen("data.old.dat","w");
	char dummy;
	
	printf("name=%s\r\n",values.name);
	printf("please enter an int\r\n");
	scanf("%d",&values.a);
	dummy = getchar();
	printf("please enter a float\r\n");
	scanf("%f",&values.b);
	dummy = getchar();
	printf("please enter a character\r\n");
	values.c=getchar();
	//printf("%c\r\n",values.c);
	dummy = getchar();
		
	printf("%s,%d,%.2f,%c\r\n",values.name,values.a,values.b,values.c);
	fprintf(pt2,"%d ,%f ,%c ,%s \r\n",values.a,values.b,values.c,&values.name);
	fclose(pt2);
}
int check_file(FILE *pt1)
{
	if(pt1==NULL){return false;}//file doesn't exist
	if(pt1!=NULL){return true;}//file exists
}