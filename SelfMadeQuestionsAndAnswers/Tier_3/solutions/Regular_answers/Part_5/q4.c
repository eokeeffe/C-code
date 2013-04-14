/*
	Tier 3 : Part 5	:	Question 4
	
	Comments below for the functions
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

struct input
{
	double number;
}array[10];

int get_numbers();
int number_input();
int calculator_main();
int add(int number_count,...);
int subtract(int number_count,...);
int divide(int number_count,...);
int multiply(int number_count,...);
int calculator_operation(int arguements);

int calculator_operation(int arguements)// get the calculator operation
{
	char string[50];
	int clean;
	for(clean=0;clean<50;clean++){string[clean]='\0';}
	
	printf("What operation are you using ?\r\n");
	printf("add\r\nsubtract\r\nmultiply\r\ndivide\r\n\n");
	fgets(string,50,stdin);
	
	if(strstr(string,"add") != NULL)
	{
		add(arguements,array[0],
					   array[1],
					   array[2],
					   array[3],
					   array[4],
					   array[5],
					   array[6],
					   array[7],
					   array[8],
					   array[9],
					    array[10]);
		return 0;
	}
	if(strstr(string,"subtract") != NULL)
	{
		subtract(arguements,array[0],
					   array[1],
					   array[2],
					   array[3],
					   array[4],
					   array[5],
					   array[6],
					   array[7],
					   array[8],
					   array[9],
					    array[10]);
		return 0;
	}
	if(strstr(string,"multiply") != NULL)
	{
		multiply(arguements,array[0],
					   array[1],
					   array[2],
					   array[3],
					   array[4],
					   array[5],
					   array[6],
					   array[7],
					   array[8],
					   array[9],
					    array[10]);
		return 0;
	}
	if(strstr(string,"divide") != NULL)
	{
		divide(arguements,array[0],
					   array[1],
					   array[2],
					   array[3],
					   array[4],
					   array[5],
					   array[6],
					   array[7],
					   array[8],
					   array[9],
					    array[10]);
		return 0;
	}
	else
	{
		printf("Please try again\r\n");
		exit(EXIT_FAILURE);
	}
}

int number_input()//simple function for getting a number
{
	int user_number;
	
	while( scanf("%d%*c",&user_number)!=1)
	{
		printf("Pleaes enter an integer\r\n");
		fflush(stdin);
	}
	return user_number;
}

int get_numbers(int count)//get the numbers for the operations
{
	int loop_count=0;
	double user_number;
	
	while(loop_count<count)
	{
		printf("Please enter a number\r\n");
		array[loop_count].number = number_input();
		loop_count++;
	}
	
	return 0;
}

int calculator_main()//function to run the addition
{
	int number_of_arguements;
	
	printf("Please enter a number of arguements\r\n");
	number_of_arguements=number_input();
	
	if(number_of_arguements > 10)
	{
		printf("Please try again with less arguements\r\n");
		exit(0);
	}
	else
	{
		get_numbers(number_of_arguements);
		calculator_operation(number_of_arguements);
		return 0;
	}
}

int subtract(int number_count,...)//function to subtract variable numbers
{
	int loop_counter=0;
	double subtracted_floats=0.0;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	while(loop_counter < number_count)
	{
		subtracted_floats -= va_arg(ap,double);//add the next arguement of type double
		//the second arguement is a safety net where the arguement will only be caught if its
		//of the type specified , in other words if you have only integers , and its looking for a 
		//double , the program wont add the double at all
		loop_counter++;
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	printf("%lf is the subtracted floats \r\n",subtracted_floats);
	
	return 0;
}

int divide(int number_count,...)//function to divide variable numbers
{
	int loop_counter=0;
	double divided_floats=0.0;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	while(loop_counter < number_count)
	{
		if(loop_counter==0)
		{
			divided_floats = va_arg(ap,double); //add the next arguement of type double
			loop_counter++;
		}
		else
		{
			divided_floats /= va_arg(ap,double);//add the next arguement of type double
			//the second arguement is a safety net where the arguement will only be caught if its
			//of the type specified , in other words if you have only integers , and its looking for a 
			//double , the program wont add the double at all
			loop_counter++;
		}
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	printf("%lf is the divided floats \r\n",divided_floats);
	
	return 0;
}

int multiply(int number_count,...)//function to multiply variable numbers
{
	int loop_counter=0;
	double multiplied_floats=0.0;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	
	while(loop_counter < number_count)
	{
		if(loop_counter==0)
		{
			multiplied_floats = va_arg(ap,double); //add the next arguement of type double
			loop_counter++;
		}
		else
		{
			multiplied_floats *= va_arg(ap,double);//add the next arguement of type double
			//the second arguement is a safety net where the arguement will only be caught if its
			//of the type specified , in other words if you have only integers , and its looking for a 
			//double , the program wont add the double at all
			loop_counter++;
		}
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	
	printf("%lf is the multiplied floats \r\n",multiplied_floats);
	
	return 0;
}

int add(int number_count,...)//function to add variable numbers
{
	int loop_counter=0;
	double added_floats=0.0;
	
	va_list ap;//create a variable called ap from va_list 

    va_start(ap, number_count);//start by taking the first arguement which
	//will tell the loop how many times to add
	
	while(loop_counter < number_count)
	{
		added_floats += va_arg(ap,double);//add the next arguement of type double
		//the second arguement is a safety net where the arguement will only be caught if its
		//of the type specified , in other words if you have only integers , and its looking for a 
		//double , the program wont add the double at all
		loop_counter++;
	}
	
	va_end(ap);	// end the use of va_list variable ap
	
	
	printf("%lf is the added floats \r\n",added_floats);
	
	return 0;
}

int main()
{
	calculator_main();
	return 0;
}