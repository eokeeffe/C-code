/*
	Tier 3 : Part 4	:	Question 2
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
	FILE *FILE_HANDLE , *fopen();
	
	FILE_HANDLE = fopen("text not here.txt","r");
	
	if(FILE_HANDLE == NULL)
	{
		print_to_error_stream(errno);
		close(FILE_HANDLE);
	}
	else
	{
		fclose(FILE_HANDLE);
		return 0;
	}
}

int print_to_error_stream(int error)
{
	fprintf(stderr,"%d is the error code , '%s' is the error name \r\n",errno,strerror(errno));
	errno = 0;	// amke sure to reset the errno when it has been set from an error
	exit(0);
}

int main ()
{
	open_file();
	return 0;
}