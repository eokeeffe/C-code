/*
	Tier 3 : Part 8	:	Question 2
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define TRUE 1

int number_counter;

int get_int();
int get_user_number();
int read_from_binary_file();
int write_to_binary_file(int user_input);
int check_if_file_exists(FILE *FILE_HANDLE);

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

int read_from_binary_file()
{
	FILE *FILE_HANDLE,*fopen();
	int get_binary_number;
	
	FILE_HANDLE = fopen("binary_number_file.dat","rb");
	
	check_if_file_exists(FILE_HANDLE);
	
	while(fread(&get_binary_number,sizeof(int),1,FILE_HANDLE) == 1)
	{
		/*
			fread works almost the same as fwrite(); 
			the first arguement is where the information will be put
			the sizeof the information being collected 
			how many pieces of the information will be collected
			the stream where the information is coming from
		*/
		printf("%d\r\n",get_binary_number);
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

int write_to_binary_file(int user_input)
{
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("binary_number_file.dat","ab+");
	
	check_if_file_exists(FILE_HANDLE);
	
	fprintf(FILE_HANDLE , "%d\r\n" , user_input);
	
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
	/*
	number_counter = 0;
	get_user_number();
	*/
	read_from_binary_file();
	
	return 0;
}