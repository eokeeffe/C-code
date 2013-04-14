/* This is the first header fie of the section used for question 4*/

#include<stdio.h>
#include<time.h>

extern int time_and_date();//all that is needed here is the function declaration to have in front of it
				   //extern to allow other programs to use this declaration

extern int time_and_date()
{
	time_t now;
	time(&now);

	printf("%s", ctime(&now));
	printf("oh yeah im from header_file.h\r\n");
	return 0;
}