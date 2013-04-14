/*
	Tier 2 : Part 1	:	Question 4
	
*/
#include<stdio.h>

int write_to_file();
int read_from_file();

int main()
{
	write_to_file();
	read_from_file();
	return 0;
}

int write_to_file()
{
	FILE *FILE_HANDLE,*fopen();
	
	FILE_HANDLE = fopen ("wrtf.txt","w");
	
	if(FILE_HANDLE==NULL)
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

int read_from_file()
{
	FILE *FILE_HANDLE,*fopen();
	
	FILE_HANDLE = fopen ("wrtf.txt","r");
	
	if(FILE_HANDLE==NULL)
	{
		printf("File cannot be Read from \r\n");
		return 0;
	}
	else
		{
			int character_variable=0; //remember characters are stored as ascii numbers anyway

			while(character_variable != EOF)
			{
				character_variable = getc(FILE_HANDLE); // get the character from the file
				
				putchar(character_variable); // put the character onto the screen
			}
		}
		
	fclose(FILE_HANDLE);
	
	return 0;
}