/*
	Tier 2 : Part 6	:	Question 3
*/
#include<stdio.h>
//previous example
#define PRINT(x) printf("%s",x);

// the same thing occurs here , the start and end are replaced at compile time with the 
// the curly braces
#define start_block {
#define end_block }

//defining the buffer space for fgets here
#define BUFFER_SPACE 50

int main()
start_block

	char user_input_string[50];
	
	PRINT("Please enter a string\r\n");
	
	fgets(user_input_string,BUFFER_SPACE,stdin);
	
	PRINT(user_input_string);
	
	return 0;	
	
end_block