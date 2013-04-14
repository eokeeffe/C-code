/*
	Tier 3 : Part 5	:	Question 2
	just about the exact same as question 1 only the arguements 
	are all there
	its the user who chooses how many are added
*/
#include<stdio.h>
#include<stdlib.h>
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
	int answer=0;
	int number_of_arguements;
	
	printf("Please enter the number of summations from 0 you want\r\n");
	printf("Maximum is 20\r\n");
	
	number_of_arguements = number_input();
	if(number_of_arguements>20)
	{
		fprintf(stderr,"%s","Sorry number wasn't in the range of 0-20\r\n");
		exit(EXIT_FAILURE);
	}
	else
	{
	
		answer = add(number_of_arguements,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19);
		
		printf("The added numbers upto %d are = %d\r\n",number_of_arguements,answer);
		
		return 0;
	}
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