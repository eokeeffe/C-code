/*
	Tier 3 : Part 9	:	Question 1
*/
#include<stdio.h>

int get_function_from_function_pointer( int ( *pt )(int,int),int x,int y);
int get_int();
int add( int x , int y);

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

int get_function_from_function_pointer( int ( *pt )(int x , int y),int x,int y)
{
	int result;

	result = (*pt)(x,y);
	
	return result;
}

int main()
{
	int number_1,number_2;
	
	fprintf(stdout,"Please enter the first number\r\n");
	number_1 = get_int();
	
	fprintf(stdout,"Please enter the second number\r\n");
	number_2 = get_int();
	
	fprintf(stdout,"%d + %d = %d \n",number_1,number_2, get_function_from_function_pointer(add,number_1,number_2));
	
	return 0;
}