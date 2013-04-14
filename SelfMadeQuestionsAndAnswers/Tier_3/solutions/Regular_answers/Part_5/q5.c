/*
	Tier 3 : Part 5	:	Question 5
	
	Comments below for the functions
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

int number_input();
int print_alphabet();
int print_characters(int number_count,...);

int number_input()//get a number
{
	int user_number;
	
	while(scanf("%d",&user_number)!=1)
	{
		printf("Please enter an integer\r\n");
		fflush(stdin);
	}
	return user_number;
}

int print_characters(int number_count,...)//print characters
{
	int loop_counter=0;
	int character;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	while(loop_counter < number_count)
	{
		character = va_arg(ap,int);
		printf("%c",character);
		loop_counter++;
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	return 0;
}

int print_alphabet()//simply print the alphabet
{
	int number_of_arguements;
	
	printf("How many characters of the alphabet do you want printed\r\n");
	number_of_arguements = number_input();
	
	if(number_of_arguements > 26)
	{
		printf("Please try a number between 1-26\r\n");
		main();
	}
	else
	{
		print_characters(number_of_arguements,
		'a','b','c','d','e','f','g','h','i','j',
		'k','l','m','n','o','p','q','r','s','t',
		'u','v','w','x','y','z');
		
		return 0;
	}
}

int main()
{
	print_alphabet();
	return 0;
}