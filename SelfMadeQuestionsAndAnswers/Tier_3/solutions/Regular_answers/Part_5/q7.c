/*
	Tier 3 : Part 5	:	Question 7
	
	this method can be used to print multiple arrays in the printing function
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

int get_number();
int print_some_integers();
int printi( int number_count , ... );

int get_number()
{
	int user_number;
	while(scanf("%d",&user_number)!=1)
	{
		printf("Please enter an integer\r\n");
		fflush(stdin);
	}
	return user_number;
}

int printi(int number_count,...)//print the numbers from the integer array
{
	int loop_counter=0;
	int* numbers;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	numbers = va_arg(ap,int*);
	
	while(loop_counter < number_count)
	{
		if(loop_counter==0)
		{
			printf(" %d ",*numbers);
			loop_counter++;
		}
		else
		{
			numbers++;
			
			printf(" %d ",*numbers);
			loop_counter++;
		}
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	return 0;
}

int print_some_integers()//simply print the integers
{
	int loop_count=0,number;
	int array[30];
	
	printf("How many numbers are you entering 0-30\r\n");
	number=get_number();
	
	if(number > 30 && number < 0)
	{
		main();
	}
	else
	{
		while(loop_count < number)
		{
			printf("Please enter a number\r\n");
			array[loop_count]=get_number();
			loop_count++;
		}
		
		printi(number,array);
		return 0;
	}
}

int main()
{
	print_some_integers();
	return 0;
}

