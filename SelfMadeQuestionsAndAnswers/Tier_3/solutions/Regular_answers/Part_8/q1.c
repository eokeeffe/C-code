/*
	Tier 3 : Part 8	:	Question 1
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//keep the while loop going unitl the control is activated
#define TRUE 1
//this counts how many items have been written
int number_counter;

int get_int();
int get_user_number();//holds the loop for the number input
int write_to_binary_file(int user_input);//append to the binary file the number the user has entered
int check_if_file_exists(FILE *FILE_HANDLE);//check if the file stream was succesful in opening

int get_int()
{
	int user_number;
	while(scanf("%d",&user_number)!=1)
	{
		fprintf(stdout,"Please enter an integer\r\n");
		fflush(stdin);
	}
	return user_number;
}

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

int write_to_binary_file(int user_input)
{
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("binary_number_file.dat","ab+");//simply append to the binary file
	
	check_if_file_exists(FILE_HANDLE);
	
	fwrite(&user_input,sizeof(int),1,FILE_HANDLE);
	/* 
	   Explanation
	   the first arguement is the address of the information to write
	   the second arguement is the size of the object to write
	   the third is the number of items to write
	   the last is the stream that the object will be written to 
	*/
	
	fclose(FILE_HANDLE);
	
	get_user_number();
	
	return 1;
}

int get_user_number()
{
	int user_input , loop_control = -1 ;
	
	while( TRUE )
	{
		fprintf(stdout,"Please enter the number to write to the binary file\r\n");
		fprintf(stdout,"number of numbers entered : %d\r\n",number_counter);
		fprintf(stdout,"enter a negative number to exit the program\r\n");
		user_input = get_int();
		
		if(user_input <= loop_control)
		{
			break;
		}
		else
		{
			number_counter ++ ;
			write_to_binary_file(user_input);
		}
	}
	
	fprintf(stdout,"Thank you for using this binary writer\r\n");
	exit(EXIT_SUCCESS);
}

int main()
{
	number_counter = 0;
	get_user_number();
	return 0;
}