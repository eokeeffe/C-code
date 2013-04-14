/*
	Tier 2 : Part 8	:	Question 4
	
	This is the calling program , each of the programs 
	and macros have been defined in the header files
	
*/
#include "myheader_q4.h"

int main()
{
	int FOO_BAR = 11;
	
	compiled_program_information();
	
	dump_me(FOO_BAR,"%d");
	
	ERROR(FOO_BAR,"%d");
	
	return 0;
}