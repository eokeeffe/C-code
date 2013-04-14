/*Evan O'Keeffe
  10324289
  question1 practical 10
*/
#define true 1
#define false 0
#include<stdio.h>

int check_file(FILE *fpt);	//checks if the file already exists

void main()
{
	FILE *fpt;
	int a;
	float b;
	char c;
	char dummy;
	printf("Please enter an int value\r\n");
	scanf("%d",&a);
	dummy=getchar();
	printf("Please enter a float value\r\n");
	scanf("%f",&b);
	dummy=getchar();
	printf("Please enter a character\r\n");
	c=getchar();
	dummy=getchar();
	
	fpt=fopen("sample.dat","w");
	
	if(check_file(fpt)!=true){fprintf(fpt," %d,%.2f,%c\r\n",a,b,c);fclose(fpt);}
	else{fclose(fpt);("sorry but your file wasn't made\r\n");main();}
}
int check_file(FILE *fpt)
{
	if(fpt==NULL){return true;}
	if(fpt!=NULL){return false;}
}