/*
	Tier 3 : Part 4	:	Question 3
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
		assertion_function(FILE_HANDLE);
		close(FILE_HANLDE);
	}
	else
	{
		fclose(FILE_HANLDE);
		return 0;
	}
}

int assertion_function(FILE *FILE_HANDLE)
{
	assert(FILE_HANDLE); // assert will work so long as the statement is false
	
	return 0;
}

int main ()
{
	open_file();
	
	return 0;
}