/* 
	This file contains the functions neccesary to have a complete and simple error log 
	If the files are included already they will have been defined , further notes look back at Tier 2 section on header files
	
	Date : 08/08/2011
	Name: Evan O ' Keeffe
	
	V2 added lines 84-86 for the date and time to be added
	
	
*/
#ifdef _STDIO_H_

#else
	#include<stdio.h>
#endif


#ifdef _STDLIB_H_

#else
	#include<stdlib.h>
#endif

#ifdef _STRING_H_

#else
	#include<string.h>
#endif

#ifdef _MATH_H_

#else
	#include<math.h>
#endif

#ifdef _ERRNO_H_

#else
	#include<errno.h>
#endif

#ifdef _ASSERT_H_

#else
	#include<assert.h>
#endif

#ifdef _SIGNAL_H_

#else
	#include<signal.h>
#endif


#ifdef _TIME_H_

#else
	#include<time.h>
#endif

// The start of the functions + decalrations of this file

#ifdef __ERROR_LOG_H_

#else
//The Main Part of the Header File 
#define __ERROR_LOG_H_

// remeber this from Tier 2 , this is extremely useful
#define log_error(identifier,token)  																								\
	FILE *FILE_HANDLE,*fopen();																										\
																																	\
	FILE_HANDLE = fopen ("Main_error_log.txt","a+");																				\
																																	\
	if(FILE_HANDLE == NULL)																											\
	{																																\
		fclose(FILE_HANDLE);																										\
		fprintf(stderr,"\r\n %s %s \r\n","Main_error_log.txt",strerror(errno));														\
		exit(0);																													\
	}																																\
	else																															\
	{																																\
		time_t t;																													\
		time(&t);																													\
		fprintf(FILE_HANDLE,"TIME + DATE : %s \r\n",ctime(&t));																		\
		fprintf(FILE_HANDLE,"FILE:%s  LINE:%d Identifier:%s = "token"\r\n",__FILE__,__LINE__,#identifier,identifier);				\
		fclose(FILE_HANDLE);																										\
		return 0;																													\
	}																																

#endif