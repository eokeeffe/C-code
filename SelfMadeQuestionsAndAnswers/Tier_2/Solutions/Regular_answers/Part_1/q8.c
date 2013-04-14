/*
	Tier 2 : Part 1	:	Question 8
	
*/
#include<stdio.h>

int read_from_file();
int write_to_file();

int main()
{
	read_from_file();
	return 0;
}

int read_from_file()
{
	FILE *FILE_HANDLE_1,*FILE_HANDLE_2,*fopen();
	
	FILE_HANDLE_1 = fopen ("q1.c","r");
	FILE_HANDLE_2 = fopen("index.txt","w");
	
	if(FILE_HANDLE_1==NULL||FILE_HANDLE_2==NULL)
	{
		printf("File cannot be Read from \r\n");
		printf("Index file cannot be created \r\n");
		return 0;
	}
	else
		{
			int character_variable=0; //remember characters are stored as ascii numbers anyway
			int count_back_slash_lines = 0; //count the / characters so that the first comment will only be read
			
			while(character_variable != EOF)
			{
				character_variable = getc(FILE_HANDLE_1); // get the character from the file
				fputc(character_variable,FILE_HANDLE_2);
				putchar(character_variable); // put the character onto the screen
				
				if(character_variable=='/'){ count_back_slash_lines++;}
				if(count_back_slash_lines==2){ character_variable=EOF; }
			}
		}
		
	fclose(FILE_HANDLE_1);
	
	return 0;
}