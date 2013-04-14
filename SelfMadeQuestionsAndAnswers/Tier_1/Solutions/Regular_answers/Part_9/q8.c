/*
	Tier 1 : Part 9	:	Question 8
	
*/
#include<stdio.h>

char* string_input(char* user_string_input,int string_size);

int main()
{
	char user_string_input[50];
	printf("Please enter a string\r\n");
	string_input(user_string_input,50);
	
	printf("You entered %s\r\n",user_string_input);
	return 0;
}

char* string_input(char* user_string_input,int string_size)
{
	int loop_count = 0,clean;
	for(clean=0;clean<string_size;clean++){user_string_input[clean]='\0';}
	
	while(loop_count < string_size)
	{
		user_string_input[loop_count] = getchar();
		
		if(user_string_input[loop_count]=='\r'){break;}
		if(user_string_input[loop_count]=='\n'){break;}
		
		loop_count++;
	}
	
	user_string_input[50]='\0';
	
	return user_string_input;
}