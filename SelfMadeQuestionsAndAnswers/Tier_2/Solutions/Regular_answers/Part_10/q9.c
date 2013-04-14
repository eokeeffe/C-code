/*
	Tier 2 : Part 10	:	Question 9
*/
#include<stdio.h>
#include<string.h>

#define line printf("line:%d\r\n",__line__);

int pointer_number_sort(int *pointer_array[], int number_of_pointer_arrays);

int main()
{
	int *pointer_array[20];
	int loop_count = 0;
	int clean , number_of_integers=10;
	
	for(clean=0;clean<20;clean++){pointer_array[clean]='\0';}
	
	while(loop_count < 10)
	{
		printf("please enter another number\r\n");
		while(scanf("%d",&pointer_array[loop_count])!=1)
		{
			fflush(stdin);
		}
		//printf("%d \r\n",pointer_array[loop_count]);
		loop_count++;
	}
	
	pointer_number_sort(pointer_array,number_of_integers);
	
	loop_count=0;
	
	while(loop_count < 11)
	{
		printf("%d \r\n",pointer_array[loop_count]);
		loop_count++;
	}
	
	return 0;
}

int pointer_number_sort(int *pointer_array[], int number_of_pointer_arrays)
{
	int fake_loop_count = 0 , real_loop_count = 0;
	
	while(real_loop_count < number_of_pointer_arrays)
	{
		if(pointer_array[fake_loop_count] > pointer_array[fake_loop_count+1])
		{
			int *temporary_integer;
			
			temporary_integer = pointer_array[fake_loop_count];
			
			pointer_array[fake_loop_count] = pointer_array[fake_loop_count+1];
			
			pointer_array[fake_loop_count+1] = temporary_integer;
		}
		fake_loop_count++;
		
		if(fake_loop_count == number_of_pointer_arrays)//bubble sort has to be loop N times 
		{											   //to make sure everything is in the right order
			fake_loop_count = 0;
			real_loop_count++;
		}
	}
	
	
	return ;
}