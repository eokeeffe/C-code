/*
	Tier 3 : Part 8	:	Question 7
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
//keep the while loop going unitl the control is activated
#define TRUE 1
int struct_counter;//count the number of structs created

int get_int();
int get_student_information();//get input for the struct variables
int seek_record();// seek the struct to read from the file
int database_main();//just holds the program loop
int read_from_binary_file();//read the binary file
int write_to_binary_file();//append to the binary 
int check_if_file_exists(FILE *FILE_HANDLE);//check if the file stream was succesful in opening

struct student_records
{
	char student_name[50];
	int student_number;
	int record_number;
}access;

struct student_records list[10];

int get_int()
{
	int user_number;
	while(scanf("%d%*c",&user_number)!=1)
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
	int counter;
	
	FILE_HANDLE = fopen("student_records.dat","wb+");//simply append to the binary file
	
	check_if_file_exists(FILE_HANDLE);
	
	for( counter =0;
		 fwrite(&list[counter],sizeof( access) , 1 , FILE_HANDLE) && counter < struct_counter;//write the entire struct to the binary file
		 counter++);
	
	fclose(FILE_HANDLE);
	
	return 1;
}

int seek_record()
{
	FILE *FILE_HANDLE , *fopen();
	int record_to_search_for;
	
	FILE_HANDLE = fopen("student_records.dat","rb");//simply append to the binary file
	
	check_if_file_exists(FILE_HANDLE);
	
	printf("Please enter the record number to search for\r\n");
	record_to_search_for = get_int();
	
	if(record_to_search_for < 1 || record_to_search_for > 10)
	{
		fprintf(stderr,"Please enter a number between 0-10\r\n");
		fclose(FILE_HANDLE);
		seek_record();
	}
	
	fseek( FILE_HANDLE , ( record_to_search_for - 1)*sizeof(access),SEEK_SET);//seek the item at position N-1 , from the stream file handle 
																			  // SEEK_SET means set the file pointer to the start of the file
	fread(&access, sizeof( access ) , 1 , FILE_HANDLE);
	
	fprintf(stdout,"Student Name:%s\r\nStudent Number:%d\r\nStudent Record:%d\r\n",access.student_name,access.student_number,access.record_number);
					
	fclose(FILE_HANDLE);
					
	exit(EXIT_SUCCESS);
}

int get_student_information()
{
	fprintf(stdout,"Please enter a student name\r\n");
	fgets(list[struct_counter].student_name,50,stdin);
	
	fprintf(stdout,"Please enter a student number\r\n");
	list[struct_counter].student_number = get_int();
	
	fprintf(stdout,"Please enter record number\r\n");
	list[struct_counter].record_number = get_int();
	
	return 1;
}

int database_main()
{
	int number_of_entries;
	
	fprintf(stdout,"Please enter the number of entries\r\n");
	number_of_entries = get_int();
	
	if(number_of_entries < 0 && number_of_entries > 10 )
	{
		fprintf(stderr,"Please enter a number between 0-10");
		main();
	}
	
	while( struct_counter < number_of_entries)
	{
		get_student_information();
		struct_counter++;
	}
	
	write_to_binary_file();
	
	seek_record();
	
	return 0;
}

int main()
{
	struct_counter = 0;
	database_main();
	
	return 0;
}