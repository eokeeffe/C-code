/*
	Tier 2 : Part 1	:	Question 10
	
	This more than likely needs some explaining 
	The dirent.h is the header file where the functions for dealing 
	with directory files is held 
	The program simply gets all the files and will put the ones with the .c
	at the end into a string array
	
	how it gets the .c files is it uses strstr which will return the pointer to the 
	last occurence of ".c" in the first string , then it checks if it is null
	If it is NULL then the file doesn't have the .c in the end , if it does 
	then the file is added to the array and the comments extracted
	
	The string array is then read each time and the name of the program 
	and the programs comments are written to 
	index.txt
	
	This is your first ever program Indexer , Well Done this was a bit of a tricky one
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <dirent.h> //for the directory working tools

#define LINE printf("%d is the line \r\n",__LINE__);

int get_all_directory_files();
int extract_comments();

//Global variable , works in the whole program
char file_names[100][20]; //this creates a string array of size 100 of which each string
						  //is 20 characters long

int main()
{
	int cleanx,cleany;
	for(cleanx=0;cleanx<100;cleanx++)
	{
		for(cleany=0;cleany<20;cleany++)
		{
			file_names[cleanx][cleany]='\0';
		}
	}
	
	get_all_directory_files();
	return 0;
}

int get_all_directory_files()
{
	char *CHECK;
	int count_files=0;
	
	
	DIR *directory_specifier;//create a variable from the DIR struct in dirent.h
    struct dirent *dir; //create another struct pointer of type dirent
  
    directory_specifier = opendir("."); //specifying to what file we are looking for
    if (directory_specifier)	//test if the specifier pointer is working or not
    {
      while ((dir = readdir(directory_specifier)) != NULL)
      {
        printf("%s\n", dir->d_name);
		if((CHECK = strstr(dir->d_name,".c"))!= NULL)
		{
			strcpy(file_names[count_files],dir->d_name);
			count_files++;
		}
      }
	  
      closedir(directory_specifier);
    }
	
	//This is to test to make sure the array is being populated with the right things
	/*
	int var;
	var = count_files;
	count_files=0;
	while(count_files < var)
	{
		printf("%s\r\n",file_names[count_files]);
		count_files++;
	}
	*/
	
	extract_comments();
	return 0;
}

int extract_comments()
{
	FILE *FILE_HANDLE_1,*FILE_HANDLE_2,*fopen();
	
	//LINE
	
	FILE_HANDLE_2 = fopen("Index.txt","w");
	if(FILE_HANDLE_2==NULL)
	{
		printf("Sorry Index.txt cannot be created \r\n");
		exit(0);
	}
	fclose(FILE_HANDLE_2);
	
	//LINE
	
	int file_count=0;
	
	//LINE
	
	while(file_names[file_count]!='\0')
	{
		FILE_HANDLE_1 = fopen (file_names[file_count],"r");
		FILE_HANDLE_2 = fopen("Index.txt","a");
		
		if(FILE_HANDLE_1==NULL||FILE_HANDLE_2==NULL)
		{
			printf("File cannot be Read from \r\n");
			printf("Index file cannot be appended too\r\n");
			return 0;
		}
		else
			{
				int character_variable=0; //remember characters are stored as ascii numbers anyway
				int count_back_slash_lines = 0; //count the / characters so that the first comment will only be read
				
				//print the file name before printing the comment to the file
				fprintf(FILE_HANDLE_2,"%d. %s\r\n\n",file_count,file_names[file_count]);
				
				while(character_variable != EOF)
				{
					character_variable = getc(FILE_HANDLE_1); // get the character from the file
					//print each letter to the file
					fputc(character_variable,FILE_HANDLE_2);
					//putchar(character_variable); // put the character onto the screen
					
					if(character_variable=='/'){ count_back_slash_lines++;}
					if(count_back_slash_lines==2){ character_variable=EOF; }
				}
				fputc('\n',FILE_HANDLE_2);
			}
			
		file_count++;
		fclose(FILE_HANDLE_1);
		fclose(FILE_HANDLE_2);
	}
			
	
	
	return 0;
}
