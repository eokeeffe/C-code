/*
	Tier 3 : Part 5	:	Question 1
*/
#include<stdio.h>
#include<stdarg.h>


int number_input();
int add_some_numbers();
int add(int number_count,...);

int number_input()//simple function for getting a number
{
	int user_number;
	
	while( scanf("%d",&user_number)!=1)
	{
		printf("Pleaes enter an integer\r\n");
		fflush(stdin);
	}
	return user_number;
}

int add_some_numbers()//function to run the addition
{
	int answer;
	int loop_counter=0;
	int number_1,number_2;
	
	printf("Please enter a number\r\n");
	number_1=number_input();
	
	printf("Please enter another number\r\n");
	number_2=number_input();
	
	answer = add(2,number_1,number_2);
	
	printf("The added numbers = %d\r\n",answer);
	
	return 0;
}

int add(int number_count,...)//function to add variable numbers
{
	int loop_counter=0;
	int added_number=0;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	while(loop_counter < number_count)
	{
		added_number += va_arg(ap,int);//add the next arguement of type integer
		loop_counter++;
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	return added_number;
}
int main()
{
	add_some_numbers();
	return 0;
}