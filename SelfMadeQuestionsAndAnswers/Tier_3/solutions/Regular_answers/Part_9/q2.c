/*
	Tier 3 : Part 9	:	Question 2
*/
#include<stdio.h>

int get_function_from_function_pointer( int ( *pt )( int , int * ),int number_of_args_to_add, int *pointer);
int get_int();
int add( int x , int y);
int addv(int number_of_arguements, int *pointer);

int get_int()
{
	int user_number;
	while( scanf("%d%*c",&user_number) != 1)
	{
		fprintf(stderr,"Please enter an integer number\r\n");
		fflush(stdin);
	}
	return user_number;
}

int add( int x , int y)
{
	return (x + y);
}

//	the variable arguements are different when using the function pointers 
//	the function pointers cannot be used with the functions of stdarg.h yet
//	so in the mean time the pointer refereneces the number array in int main()
int addv(int number_of_arguements, int *pointer)
{
	int counter , added_numbers = *pointer;
	
	for(counter = 0 ; counter < number_of_arguements ; counter++)
	{
		added_numbers += *pointer;
		*pointer++;
	}
	
	return added_numbers;
}

int get_function_from_function_pointer( int ( *pt )(int number_of_args_to_add , int* pointer),int number_of_args_to_add,int *pointer)
{
	int result;
	

	result = (*pt)(number_of_args_to_add, pointer);
	
	return result;
}

int main()
{
	int add,number_of_args_to_add;
	int number_array[]={0,1,2,3,4,5,6,7,8,9,10};
	
	fprintf(stdout,"Please enter the number of arguements to add from 0-10\r\n");
	number_of_args_to_add = get_int();
	
	fprintf(stdout,"result is :%d \n",get_function_from_function_pointer( addv ,number_of_args_to_add, number_array));
	
	return 0;
}