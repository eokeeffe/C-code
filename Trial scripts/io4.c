/*
	low level I/O example 3
	using typedef struct with fseek function
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
	int n;
	
	if((partfile = fopen("parts.dat","rb")) ==NULL)
	{
		printf("Cannot open the file\r\n");
		return 0;
	}
	
	printf("Please enter record number\r\n");
	scanf("%d",&n);
	
	fseek(partfile , (n-1)*sizeof(PartRecord),SEEK_SET);
	fread(&part,sizeof(PartRecord),1,partfile);
	
	/*printing the contents of this section of the file*/
	
	printf("\nPartNumber: %s\n",part.partnum);
	printf("Part name:%s\n",part.name);
	printf("Quantity in stock: %d\n",part.amtinstock);
	printf("Unit price: E%-6.2f\n",part.unitprice);
	
	fclose(partfile);
	return 0;
}