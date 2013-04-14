/*
	Tier 2 : Part 1	:	Question 7
	
*/
#include<stdio.h>

int read_from_file();

int main()
{
	read_from_file();
	return 0;
}

int read_from_file()
{
	FILE *FILE_HANDLE,*fopen();
	
	FILE_HANDLE = fopen ("q1.c","r");
	
	if(FILE_HANDLE==NULL)
	{
		printf("File cannot be Read from \r\n");
		return 0;
	}
	else
		{
			int character_variable=0; //remember characters are stored as ascii numbers anyway
			int count_back_slash_lines = 0; //count the / characters so that the first comment will only be read
			
			while(character_variable != EOF)
			{
				character_variable = getc(FILE_HANDLE); // get the character from the file
				putchar(character_variable); // put the character onto the screen
				
				if(character_variable=='/'){ count_back_slash_lines++;}
				if(count_back_slash_lines==2){ character_variable=EOF; }
			}
		}
		
	fclose(FILE_HANDLE);
	
	return 0;
}