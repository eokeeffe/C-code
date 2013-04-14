/*
	Tier 3 : Part 8	:	Question 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//keep the while loop going unitl the control is activated
#define TRUE 1
//this counts how many items have been written
int string_counter;

int read_from_binary_file();//read the string from the binary file
int get_user_string();//holds the loop for the number input
int write_to_binary_file(char user_string[0]);//append to the binary file the string the user has entered
int check_if_file_exists(FILE *FILE_HANDLE);//check if the file stream was succesful in opening

int check_if_file_exists(FILE *FILE_HANDLE)
{
	if(FILE_HANDLE == NULL)
	{
		fprintf(stderr,"%s , ending program\r\n",strerror(errno));
		exit(EXIT_FAILURE);
		return 0;
	}
	else
	{
		return 1;
	}
}

int read_from_binary_file()
{
	FILE *FILE_HANDLE,*fopen();
	char string_cahracter;
	
	FILE_HANDLE = fopen("binary_string_file.dat","rb");
	
	check_if_file_exists(FILE_HANDLE);
	
	while(fread(&string_cahracter,sizeof(char),1,FILE_HANDLE) == 1)
	{
		/*
			fread works almost the same as fwrite(); 
			the first arguement is where the information will be put
			the sizeof the information being collected 
			how many pieces of the information will be collected
			the stream where the information is coming from
		*/
		printf("%c",string_cahracter);
	}
	if (feof(FILE_HANDLE))//check that the feof has been acitvated to make sure the file is at the end
	{
		printf("End of list\r\n");
	}
	else
	{
		printf("Error reading file\r\n");
	}
	
	fclose(FILE_HANDLE);
	
	return 1;
}

int write_to_binary_file(char user_string[0])
{
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("binary_string_file.dat","wb+");//simply append to the binary file
	
	check_if_file_exists(FILE_HANDLE);
	
	fwrite(&user_string,sizeof(char),50,FILE_HANDLE);
	/* 
	   Explanation
	   the first arguement is the address of the information to write
	   the second arguement is the size of the object to write
	   the third is the number of items to write
	   the last is the stream that the object will be written to 
	*/
	
	fclose(FILE_HANDLE);
	
	get_user_string();
	
	return 1;
}

int get_user_string()
{
	char user_string[50];
	char *check_for_quit;
	
	while( TRUE )
	{
		fprintf(stdout,"Please enter the string to write to the binary file\r\n");
		fprintf(stdout,"number of strings entered : %d\r\n",string_counter);
		fprintf(stdout,"enter NULL to exit the program\r\n");
		fgets(user_string,50,stdin);
		
		check_for_quit = strstr(user_string,"NULL");
		
		if(check_for_quit != NULL)
		{
			break;
		}
		else
		{
			string_counter ++ ;
			write_to_binary_file(user_string);
		}
	}
	
	fprintf(stdout,"Thank you for using this binary writer\r\n");
	exit(EXIT_SUCCESS);
}

int main()
{
	//string_counter = 0;
	//get_user_string();
	read_from_binary_file();
	return 0;
}