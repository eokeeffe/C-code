/*
	Tier 2 : Part 1	:	Question 6
	
*/
#include<stdio.h>

int write_to_file();
int read_from_file(char user_string_input[0]);

int main()
{
	write_to_file();
	return 0;
}

int write_to_file()
{
	FILE *FILE_HANDLE,*fopen();
	
	char user_string_input[50],second_user_input[50];
	
	printf("Please enter a file Name to write to \r\n");
	scanf("%s",&user_string_input);
	
	FILE_HANDLE = fopen (user_string_input,"w");
	
	if(FILE_HANDLE==NULL)
	{
		printf("File cannot be written to \r\n");
		return 0;
	}
	else
		{
			printf("Please enter something to write to the file\r\n");
			fscanf(stdin,"%s",second_user_input);
			int loop_count = 0 ,control_statement = 8;
			
			while(loop_count < control_statement)
			{
				fprintf(FILE_HANDLE,"%sr\n",second_user_input);
				loop_count++;
			}
		}
		
	fclose(FILE_HANDLE);
	
	read_from_file(user_string_input);
	
	return 0;
}

int read_from_file(char user_string_input[0])
{
	FILE *FILE_HANDLE,*fopen();
	
	FILE_HANDLE = fopen (user_string_input,"r");
	
	if(FILE_HANDLE==NULL)
	{
		printf("File cannot be Read from \r\n");
		return 0;
	}
	else
		{	
			char return_character;
			int character_variable=0; //remember characters are stored as ascii numbers anyway
			int count_new_lines = 0; //count the new line characters to see how many sentences there are
			
			while(character_variable != EOF)
			{
				character_variable = getc(FILE_HANDLE); // get the character from the file
				
				if(character_variable=='\n'){ count_new_lines++;}
				
				putchar(character_variable); // put the character onto the screen
				
				if(count_new_lines == 4) // wait unitl user presses enter to continue
				{
					printf("Please press enter to continue \r\n");
					while ( return_character !='\n' && return_character !='\r')
					{
						return_character = getchar();
					}
					
					count_new_lines++;//will stop it repeating for every character while its 
									  // at 4
				}
			}
		}
		
	fclose(FILE_HANDLE);
	
	return 0;
}