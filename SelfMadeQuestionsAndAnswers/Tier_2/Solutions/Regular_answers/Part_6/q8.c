/*
	Tier 2 : Part 6	:	Question 8
*/
#include<stdio.h>
int main()
{
	FILE *FILE_HANDLE, *fopen();
	
	FILE_HANDLE = fopen("compilation_log.txt","w");
	
	if(FILE_HANDLE == NULL)
	{
		printf("Cannot create compilation log here\r\n");
		return 0;
	}
	
	else
	{
		fprintf(FILE_HANDLE,"FILE NAME:%s \r\n",__FILE__);
		fprintf(FILE_HANDLE,"Function Called from : %s\r\n",__func__);
		fprintf(FILE_HANDLE,"Date and time Compiled: %s %s\r\n",__DATE__,__TIME__);
		fprintf(FILE_HANDLE,"line called from : %d\r\n",__LINE__);
		
		if(__STDC__==1)
		{
			fprintf(FILE_HANDLE,"File Follows ANSI C standard");
		}
		if(__STDC__!=1)
		{
			fprintf(FILE_HANDLE,"File doesn't Follow ANSI C standard");
		}
		
	}
	
	fclose(FILE_HANDLE);
	return 0;	
}