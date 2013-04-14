/*
	Tier 3 : Part 4	:	Question 4
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<assert.h>

int open_file()
{
	FILE *stdin_handle,*stdout_handle,*stderr_handle , *fopen();
	FILE *FILE_HANDLE;
	
	stdin_handle = stdin ; // simply making a secondary stream that 
						   // will work on this one , helps when closing a stream
	stdout_handle = stdout ;
	stderr_handle = stderr ;
	
	FILE_HANDLE = fopen("redireted.txt","a+");
	
	if(stdin_handle == NULL)
	{
		print_to_error_stream( stdin_handle , 0 );
		close(stdin_handle);
	}
	if(stdout_handle == NULL)
	{
		print_to_error_stream( stdout_handle , 1 );
		close(stdout_handle);
	}
	if(stderr_handle == NULL)
	{
		print_to_error_stream( stderr_handle , 2 );
		close(stderr_handle);
	}
	if(FILE_HANDLE == NULL)
	{
		print_to_error_stream( FILE_HANDLE , 0 );
		close(FILE_HANDLE );
	}
	else
	{
		int user_number;
		char user_string[50];
		
		printf("Please enter a number \r\n");
		scanf("%d%*c",&user_number);
		
		printf("Please enter a string \r\n");
		fgets(user_string,50,stdin);
		
		printf("You entered %d for the number and %s for the string \r\n",user_number,user_string);
		
		fprintf(FILE_HANDLE ,"stdin = %d\r\n",user_number  );
		fprintf(FILE_HANDLE ,"stdout = %d\r\n",user_number );
		fprintf(FILE_HANDLE ,"stderr = %d\r\n",user_number );
		
		fprintf(FILE_HANDLE ,"stdin = %s\r\n",user_string   );
		fprintf(FILE_HANDLE ,"stdout = %s\r\n",user_string  );
		fprintf(FILE_HANDLE ,"stderr = %s\r\n",user_string  );
		
		fprintf(stdin_handle ,"printing to stdin = %d %s\r\n",user_number,user_string   );
		fprintf(stdout_handle ,"printing to stdout =%d %s\r\n",user_number,user_string  );
		fprintf(stderr_handle ,"printing to stderr =%d %s\r\n",user_number,user_string  );
		
		fclose(stdin_handle);
		fclose(stdout_handle);
		fclose(stderr_handle);
		fclose(FILE_HANDLE);
		return 0;
	}
}

int print_to_error_stream(FILE *handle , int stream_number )
{
	fprintf(stderr,"%d is the error and '%s' is the error message\r\n",errno,strerror(errno));
	fprintf(stderr,"stream number %d cannot be accessed \r\n",stream_number);
	
	return 0;
}

int main ()
{
	open_file();
	
	return 0;
}