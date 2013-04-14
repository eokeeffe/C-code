/*Evan O'Keeffe
  10324289
  question4 practical 10
*/
#define true 1
#define false 0
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int check_file(FILE *fpt);	//checks if the file already exists
FILE *pt1,*pt2,*fopen();

int main()
{
	char name[20];
	char new[20];
	
	//name[20]='\0';
	//name[0]='i';
	//name[1]='e';
	//new[20]='\0';
	
	pt1 = fopen("sample1.old.dat","r");
	pt2= fopen("sample1.new.dat","w");
	
	if(check_file(pt1)==true)
	{
		fgets(name,20,pt1);
		fclose(pt1);
		printf("name= %s\r\n",name);
	}
	if(check_file(pt1)==false)
	{
		printf("sorry but the file ain't there\r\n");
		fclose(pt1);
		return 0;
	}
	if(check_file(pt2)==true)
	{
		printf("name= %s\r\n",name);
		printf("Please enter a new string\r\n");
		gets(new);
		fprintf(pt2,"%s",new);
		fclose(pt2);
	}
	if(check_file(pt2)==false)
	{
		fclose(pt2);
		printf("sorry but the file wasn't there or the permission wasn't there\r\n");
		return 0;
	}
}

int check_file(FILE *fpt)
{
	if(pt1==NULL){return true;}
	if(pt1!=NULL){return false;}
	if(pt2!=NULL){return true;}
	if(pt2==NULL){return false;}
}