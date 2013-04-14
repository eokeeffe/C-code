/*
  Low level I/O example 1
  writing a binary file
*/

#include<stdio.h>

int main()
{
	FILE *intfile;
	int num;
	
	if((intfile=fopen("num.dat","wb"))==NULL)
	{
		printf("Cannot open file\r\n");
		return 0;
	}
	
	while(scanf("%d",&num)==1)
	{
		fwrite(&num,sizeof(int),1,intfile);
		/*
		&num specifies the address of items to be written
		sizeof(int) is the size of the item to be written
		1 specifies that one item will be written
		intfile specifies the file to which the items will be written to 
		*/
	}
	fclose(intfile);
	return 0;
}