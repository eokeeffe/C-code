/*
	Tier 3 : Part 5	:	Question 3
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>


int number_input();
int add_some_numbers();
double add(int number_count,...);

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
	
		answer = add(number_of_arguements,0,1.1,2,3.3,4,5.5,6,
		7.7,8,9.9,10,11.11,12,13.13,14,15.15,16,17.17,18,19.19);
		
		printf("The added numbers upto %d are = %d\r\n",number_of_arguements,answer);
		
		return 0;
	}
}

double add(int number_count,...)//function to add variable numbers
{
	int loop_counter=0;
	int added_integers=0;
	double added_floats=0.0;
	double added_numbers=0;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	while(loop_counter < number_count)
	{
		added_integers += va_arg(ap,int);//add the next arguement of type integer
		added_floats += va_arg(ap,double);//add the next arguement of type double
		//the second arguement is a safety net where the arguement will only be caught if its
		//of the type specified , in other words if you have only integers , and its looking for a 
		//double , the program wont add the double at all
		loop_counter++;
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	printf("%d is the added integers \r\n",added_integers);
	printf("%f is the added floats \r\n",added_floats);
	
	added_numbers = (double)added_integers + added_floats;
	
	return added_numbers;
}

int main()
{
	add_some_numbers();
	return 0;
}