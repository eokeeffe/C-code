/*
	Tier 2 : Part 1	:	Question 9
	
*/
#include<stdio.h>
#include<stdlib.h>

int read_file(char user_character,char* file_name);
int get_string();

int main()
{
	char user_character_input,file_name[50];
	
	printf("Please enter the character you want to check\r\n");
	printf("For the number of occurences of \r\n");
	user_character_input = getchar();
	
	printf("Please enter the File name you want to check\r\n");
	printf("For the number of occurences of %c\r\n",user_character_input);
	fscanf(stdin,"%s",file_name);
	
	read_file(user_character_input,file_name);
	
	return 0;
}

int read_file(char user_character,char* file_name)
{
	int character_occurences=0;
	int character_variable=0;
	
	FILE *FILE_HANDLE,*fopen();
	
	FILE_HANDLE = fopen( file_name ,"r");
	
	while(character_variable != EOF)
	{
		character_variable = getc(FILE_HANDLE);
		if(character_variable == user_character){character_occurences++;}
	
	}
	
	printf("%c occurs %d times in %s file\r\n",user_character,character_occurences,file_name);
	
	fclose(FILE_HANDLE);

	return 0;
}