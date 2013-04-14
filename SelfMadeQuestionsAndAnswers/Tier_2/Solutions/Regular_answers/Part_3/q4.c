/*
	Tier 2 : Part 3	:	Question 4
*/
#include<stdio.h>

int main(int argc,char *argv[])
{
	FILE *FILE_HANDLE_1,*FILE_HANDLE_2,*fopen();
	
	FILE_HANDLE_1 = fopen(argv[1],"r" );
	FILE_HANDLE_2 = fopen(argv[2],"w" );
	
	if(FILE_HANDLE_1==NULL)
	{
		printf("Cannot open %s for reading\r\n",argv[1]);
	}
	if(FILE_HANDLE_2==NULL)
	{
		printf("Cannot open %s for writing\r\n",argv[2]);
	}
	else
		{
			int character_variable=0;
			
			while(character_variable!=EOF)
			{
				character_variable = getc(FILE_HANDLE_1);
				fputc(character_variable,FILE_HANDLE_2);
			}
			
			fclose(FILE_HANDLE_1);
			fclose(FILE_HANDLE_2);
			
			printf("%s was succesfully copied to %s \r\n",argv[1],argv[2]);
		}
		
	
	return 0;
}