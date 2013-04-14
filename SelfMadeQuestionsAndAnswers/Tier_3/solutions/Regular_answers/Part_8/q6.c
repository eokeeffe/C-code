/*
	Tier 3 : Part 8	:	Question 6
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//keep the while loop going unitl the control is activated
#define TRUE 1

int get_int();
int get_student_information();//holds the loop for the number input
int read_from_binary_file();//read the binary file
int write_to_binary_file();//append to the binary 
int check_if_file_exists(FILE *FILE_HANDLE);//check if the file stream was succesful in opening

struct student_records
{
	char student_name[50];
	int student_number;
	int record_number;
}access;

int get_int()
{
	int user_number;
	while(scanf("%d",&user_number)!=1)
	{
		fprintf(stderr,"Please enter a number\r\n");
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
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("student_records.dat","rb");//simply append to the binary file
	
	check_if_file_exists(FILE_HANDLE);
	
	fread(&access, sizeof( access ) , 1 , FILE_HANDLE); // the easiest reading of a struct in C
	
	fprintf(stdout,"Student Name:%s\r\nStudent Number:%d\r\nStudent Record:%d",access.student_name,access.student_number,access.record_number);
	
	fclose(FILE_HANDLE);
	
	return 1;
}

int write_to_binary_file()
{
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("student_records.dat","wb+");//simply append to the binary file
	
	check_if_file_exists(FILE_HANDLE);
	
	fwrite(&access,sizeof( access) , 1 , FILE_HANDLE);//write the entire struct  to the binary file
	
	fclose(FILE_HANDLE);
	
	return 1;
}

int get_student_information()
{
	fprintf(stdout,"Please enter a student name\r\n");
	fgets(access.student_name,50,stdin);
	
	fprintf(stdout,"Please enter a student number\r\n");
	access.student_number = get_int();
	
	fprintf(stdout,"Please enter record number\r\n");
	access.record_number = get_int();
	
	write_to_binary_file();
	
	fprintf(stdout,"Thank you for using this binary writer\r\n");
	exit(EXIT_SUCCESS);
}

int main()
{
	//get_student_information();
	read_from_binary_file();
	return 0;
}