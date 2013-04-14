/*
	Tier 2 : Part 3	:	Question 10
	
	using the pointer function strstr again here 
	remeber that it will return a null pointer if the searched for string doesn't occur 
	in the string from the file , if the pointer is non NULL then the string does occur 
	and you can simply increment a number for it 
	
	This program also prints out the lines where the string occurs
*/
#include<stdio.h>
#include<string.h>
#define LINE printf("%d is the line \r\n",__LINE__);

int main(int argc,char *argv[])
{
	FILE *FILE_HANDLE,*fopen();
	
	FILE_HANDLE = fopen (argv[1],"r");
	
	if(FILE_HANDLE==NULL)
	{
		printf("%s cannot be opened for reading \r\n",argv[1]);
		return 0;
	}
	else
		{
			int character_variable=0,character_count=0,string_occurences=0,line_number=0;
			int line_number_array[200],clean;
			char line_from_file[80];
			char string_to_search_for[50];
			
			for(clean=0;clean<200;clean++){line_number_array[clean]='\0';}
			
			//LINE
			
			strcpy (string_to_search_for,argv[2]);
			
			while(character_variable != EOF)
			{
				//LINE
				
				while(character_variable!='\n')
				{
					//LINE
					
					character_variable = getc(FILE_HANDLE);
					line_from_file[character_count] = character_variable;
					character_count++;
				}
				
				if(character_variable=='\n'){line_number++;}
					
				if(strstr(line_from_file, string_to_search_for) != NULL)
				{
					string_occurences++;
					line_number_array[line_number]=line_number;
				}
				
				//LINE
				
				character_variable = getc(FILE_HANDLE);
				character_variable = getc(FILE_HANDLE);
			}
			
			printf("The string : %s : occurs %d times in the file %s\r\n",argv[2],string_occurences,argv[1]);
			
			int loop_count;
			
			for(loop_count = 0;loop_count<line_number;loop_count++)
			{
				if(line_number_array[loop_count]!=0)
				{
					printf("%s occurs on line %d\r\n",argv[2],line_number_array[loop_count]);
				}
			}
		
		}
	fclose(FILE_HANDLE);
	return 0;
}