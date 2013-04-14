/*Evan O'Keeffe
  10324289
  question3 practical 10
*/
#define true 1
#define false 0
#include<stdio.h>

int check_file(FILE *fpt);	//checks if the file already exists
void write_to_file();

void main()
{
	FILE *fpt,*fopen();
	int a;
	float b;
	char c;
	char dummy;
	dummy=getchar();
	
	fpt=fopen("sampleold.dat","r");
	//printf("here 1\r\n");
	
	if(check_file(fpt)==false)
	{
		//printf("here2\r\n");
		fscanf(fpt," %d,%f,%c",&a,&b,&c);
		//printf("here3\r\n");
		printf("sampleold values a=%d,b=%.2f,c=%c\r\n",a,b,c);
		fclose(fpt);
		write_to_file();
	}
	if(check_file(fpt)==true)
		{
			fclose(fpt);
			printf("sorry but your file wasn't read\r\n");
			main();
		}
}

void write_to_file()
{
	FILE *fpt,*fopen();
	int a;
	float b;
	char c;
	char dummy;
	
	printf("Please enter a new int value\r\n");
	scanf("%d",&a);
	dummy=getchar();
	
	printf("Please enter a new float value\r\n");
	scanf("%f",&b);
	dummy=getchar();
	
	printf("Please enter a new character\r\n");
	c=getchar();
	dummy=getchar();
	
	fpt=fopen("samplenew.dat","w");
	
	if(check_file(fpt)!=true){fprintf(fpt," %d,%.2f,%c\r\n",a,b,c);fclose(fpt);}
	else{fclose(fpt);("sorry but your file wasn't made\r\n");main();}
	
	
}

int check_file(FILE *fpt)
{
	if(fpt==NULL){return true;}
	if(fpt!=NULL){return false;}
}
