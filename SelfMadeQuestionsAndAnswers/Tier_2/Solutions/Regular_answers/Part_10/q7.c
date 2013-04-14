/*
	Tier 2 : Part 10	:	Question 7
*/
#include<stdio.h>

int find_number(int *pointer,int number_to_search_for);

int main()
{
	int loop_count = 0;
	int *pointer_1,user_number_array[40];
	int number_to_search_for;
	
	while(loop_count < 10)
	{
		printf("please enter another number\r\n");
		while(scanf("%d",&user_number_array[loop_count])!=1)
		{
			fflush(stdin);
		}
		loop_count++;
	}
	
	pointer_1 = &user_number_array[0];
	
	printf("please enter a number to search for in the array\r\n");
	
	while(scanf("%d",&number_to_search_for)!=1)
	{
			fflush(stdin);
	}
	
	find_number( pointer_1 ,number_to_search_for);
	
	return 0;
}

int find_number(int *pointer,int number_to_search_for)
{
	int loop_count = 0 , array_counter=0, array[40];
	int clean;
	int temp_comparison_number;
	
	for(clean=0;clean<40;clean++){array[clean]=0;}
	
	while(loop_count  < 40)
	{
		temp_comparison_number = *pointer;
		
		if( temp_comparison_number == number_to_search_for)
		{
			array[array_counter] =(int)&pointer;
			array_counter++;
		}
		
		*pointer++;
		loop_count++;
	}
	
	loop_count=0;
	while(loop_count<40)
	{
		if(array[loop_count]!=0)
		{
			printf("%d occurs in location %d in memory \r\n",number_to_search_for,array[loop_count]);
		}
		loop_count++;
	}
	
	return ;
}