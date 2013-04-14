/*
	Tier 2 : Part 3	:	Question 7
	
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
	FILE_HANDLE_2 = fopen(argv[2],"r");
	
	//LINE
	
	if(FILE_HANDLE_1==NULL)
	{
		printf("Cannot open %s for reading \r\n",argv[1]);
		return 0;
	}
	if(FILE_HANDLE_2==NULL)
	{
		printf("Cannot open %s for reading \r\n",argv[2]);
		return 0;
	}
	else
		{
			//LINE
			
			int character_variable_1=0,character_variable_2=0;
			int comparison=0,percentage=0;
			
			while(character_variable_1!=EOF&&character_variable_2!=EOF)
			{
				character_variable_1=getc(FILE_HANDLE_1);
				character_variable_2=getc(FILE_HANDLE_2);
				
				if(character_variable_1==character_variable_2)
				{
					comparison++; // counts the total characters that are the same
				}
				
				percentage++;// counts the total characters being checked
			
			}
			
			comparison /= percentage;
			comparison *= 100;
			
			printf("%s has %d%% in common with %s\r\n",argv[1],comparison,argv[2]);
			
			fclose(FILE_HANDLE_1);
			fclose(FILE_HANDLE_2);
			return 0;
			
			
		}
		
	fclose(FILE_HANDLE_1);
	fclose(FILE_HANDLE_2);

	return 0;
}