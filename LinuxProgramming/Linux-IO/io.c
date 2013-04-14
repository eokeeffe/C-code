/*
*	This program checks whether the io is 
*	redirected or not
*/
#include<unistd.h>

	if( isatty(STDIN_FILENO) == 0 )
	{
		//input is pipe or file
	}

	if( isatty(STDOUT_FILENO) == 0 )
	{
		//output is redirected/piped
	}