/*
	low level I/O example 3
	using typedef struct with fwrite
*/
#include<stdio.h>

typedef struct partrecord
{
	char partnum[7];
	char name[25];
	int amtinstock;
	float unitprice;
}PartRecord;

int main()
{
	FILE *partfile;
	PartRecord part;
	
	if((partfile = fopen("parts.dat","wb")) ==NULL)
	{
		printf("Cannot open the file\r\n");
		return 0;
	}
	
	while(scanf("%s %s %d %f",part.partnum,part.name,&part.amtinstock,&part.unitprice)==4)
	{
		if(fwrite(&part,sizeof(PartRecord),1,partfile)!=1)
		{
			printf("Error writing file\r\n");
			return 0;
		}
	}
	
	fclose(partfile);
	return 0;
}