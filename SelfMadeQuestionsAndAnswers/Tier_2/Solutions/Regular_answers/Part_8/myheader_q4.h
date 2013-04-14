/* My Header file for question 4*/
#include<stdio.h>
//the definitions here are from previous sections

#define dump_me(x,fmt) printf("%s:%u: %s="fmt,__FILE__,__LINE__,#x,x);

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

#define PRINT_DATE_AND_TIME_COMPILED printf("%s %s is the date and time this \
											 program was Compiled\r\n",__DATE__,__TIME__);
// __DATE__ and __TIME__ are other macros defined in stdio
// make sure not to try and use them to tell current time 
// they will only work at compile time and that will stick with the program

//programs for the file writing are from previous programs
int compiled_program_information()
{
	FILE *FILE_HANDLE, *fopen();
	
	FILE_HANDLE = fopen("compilation_log.txt","w");
	
	if(FILE_HANDLE == NULL)
	{
		printf("Cannot create compilation log here\r\n");
		return 0;
	}
	
	else
	{
		fprintf(FILE_HANDLE,"FILE NAME:%s \r\n",__FILE__);
		fprintf(FILE_HANDLE,"Function Called from : %s\r\n",__func__);
		fprintf(FILE_HANDLE,"Date and time Compiled: %s %s\r\n",__DATE__,__TIME__);
		fprintf(FILE_HANDLE,"line called from : %d\r\n",__LINE__);
		
		if(__STDC__==1)
		{
			fprintf(FILE_HANDLE,"File Follows ANSI C standard");
		}
		if(__STDC__!=1)
		{
			fprintf(FILE_HANDLE,"File doesn't Follow ANSI C standard");
		}
		
	}
	return 1;
}
