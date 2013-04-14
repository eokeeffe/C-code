/*
	Tier 2 : Part 7	:	Question 10
	
	This is a very handy debugging macro , this is simply printing the error to the stderr stream and 
	prints the error in Error_log.txt , this is very handy for later programs especially games
	
*/
#include<stdio.h>
#include<string.h>

#define ERROR(identifier,token) 																						\
			FILE *FILE_HANDLE,*fopen();																					\
			FILE_HANDLE = fopen("Error_log.txt","a+");																	\
			if(FILE_HANDLE == NULL){printf("Cannot create error log\r\n"); return 0;}									\
			else																										\
			{																											\
			 fprintf(FILE_HANDLE,"FILE:%s  LINE:%d Identifier:%s = "token"\r\n",__FILE__,__LINE__,#identifier,identifier);	\
			 fprintf(stderr,"FILE:%s  LINE:%d Identifier:%s = "token"\r\n",__FILE__,__LINE__,#identifier,identifier);  \
			 fclose(FILE_HANDLE);																						\
			}
int main()
{
	char bad_string[10];
	strcpy(bad_string,"This was a bad string");
	
	ERROR(bad_string,"%s")
	
	return 0;
}