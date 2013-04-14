/*
	Tier 2 : Part 1	:	Question 3
	
*/
#include<stdio.h>

int main()
{
	FILE *FILE_HANDLE,*fopen();
	
	FILE_HANDLE = fopen ("wrtf.txt","w");
	
	if(FILE_HANDLE==NULL) // make sure to check if the file can be read/written to 
	{
		printf("File cannot be written to \r\n");
		return 0;
	}
	else
		{
			fprintf(FILE_HANDLE,"Hello World in .txt format :-) \r\n");
		}
	
	fclose(FILE_HANDLE);
	
	return 0;
}