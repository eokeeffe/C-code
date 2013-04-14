/*
	Tier 3 : Part 5	:	Question 6
	
	Comments below for the functions
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

int print_some_strings();
int prints( int number_count , ... );

int prints(int number_count,...)//print characters
{
	int loop_counter=0;
	char* string;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	while(loop_counter < number_count)
	{
		string = va_arg(ap,char*);// look for a string pointer , as seen in the pointer section
									 // this will allow for the 
		printf("%s",string);
		loop_counter++;
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	return 0;
}

int print_some_strings()//simply print the alphabet
{
	char string_1[50],string_2[50];
	
	printf("Please enter string 1\r\n");
	fgets(string_1,50,stdin);
	
	printf("Please enter string 2\r\n");
	fgets(string_2,50,stdin);
	
	prints(2,string_1,string_2);
	
	return 0;
}

int main()
{
	print_some_strings();
	return 0;
}