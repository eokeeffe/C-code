/*
	Tier 2 : Part 3	:	Question 8
	
	This program will compare 2 files and return how much they are a like
	in percentage
*/
#include<stdio.h>
#include<string.h>
#define LINE printf("%d is the line \r\n",__LINE__);

int main(int argc,char *argv[])
{
	FILE *FILE_HANDLE_1,*FILE_HANDLE_2,*fopen();
	
	//LINE
	
	FILE_HANDLE_1 = fopen(argv[1],"r");
	
	//LINE
	
	if(FILE_HANDLE_1==NULL)
	{
		printf("Cannot open %s for reading \r\n",argv[1]);
		return 0;
	}
	else
		{
			//LINE
			char return_key;
			int character_variable_1=0;
			int line_number=0;
			
			while(character_variable_1!=EOF)
			{
				character_variable_1=getc(FILE_HANDLE_1);
				
				if(character_variable_1=='\n')
				{
					line_number++;
				}
				
				if((line_number%5)==0)
				{
					line_number++;
					printf("\n\t\t\t\t\t\t\t Please press enter to continue\r\n"); // so it doesn't show up so much in the code
					return_key = getchar();
				}
				
				putc(character_variable_1,stdout);
			
			}
			
			fclose(FILE_HANDLE_1);
			return 0;
			
			
		}
		
	fclose(FILE_HANDLE_1);

	return 0;
}