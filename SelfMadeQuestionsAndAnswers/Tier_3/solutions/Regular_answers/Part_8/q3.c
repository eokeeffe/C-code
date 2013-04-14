/*
	Tier 3 : Part 8	:	Question 3
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//keep the while loop going unitl the control is activated
#define TRUE 1
//this counts how many items have been written
int string_counter;

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

int write_to_binary_file(char user_string[0])
{
	FILE *FILE_HANDLE , *fopen();
	int counter=0 , string_length;
	
	string_length = strlen(user_string);
	
	FILE_HANDLE = fopen("binary_string_file.dat","ab+");//simply append to the binary file
	
	check_if_file_exists(FILE_HANDLE);
	
	while(counter < string_length)
	{
		fwrite(&user_string[counter],sizeof(char),1,FILE_HANDLE);// better to print character by character , less you need to 
																 // set all characters but the used ones to NULL
		/* 
		   Explanation
		   the first arguement is the address of the information to write
		   the second arguement is the size of the object to write
		   the third is the number of items to write
		   the last is the stream that the object will be written to 
		*/
		counter++;
	}
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
	string_counter = 0;
	get_user_string();
	return 0;
}