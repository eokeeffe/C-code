/*
  Low level I/O example 2
  reading a binary file
*/

#include<stdio.h>

int main()
{
	FILE *intfile;
	int num;
	
	if((intfile=fopen("num.dat","rb"))==NULL)
	{
		printf("Cannot open file\r\n");
		return 0;
	}
	
	while(fread(&num,sizeof(int),1,intfile)==1)
	{
		printf("%d\r\n",num);
		/*
		
		*/
	}
	if (feof(intfile)){printf("End of list\r\n");}
	else
		{printf("Error reading file\r\n");}
		
	fclose(intfile);
	return 0;
}