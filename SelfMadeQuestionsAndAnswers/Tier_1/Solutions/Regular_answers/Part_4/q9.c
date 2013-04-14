/*
	Tier 1 : Part 4	:	Question 9
	
	The program can be implemented with any one of the sorting algorithms
	
	In this case its the easiest one , the Bubble Sort
*/
#include<stdio.h>

int main()
{

	// number_array[0] = 1
	// number_array[1] = 2
	// number_array[2] = 3
	// number_array[3] = 4
	// number_array[4] = 5
	// number_array[5] = 6
	// number_array[6] = 7
	// number_array[7] = 8
	// number_array[8] = 9
	// number_array[9] = 10
	
	int number_array[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int loop_count = 0 , control_statement = 10;
	
	int temporary_number ;
	
	while( loop_count < control_statement )
	{
		printf(" %d in number_array[%d] \r\n" , number_array[loop_count] ,loop_count );
		loop_count++;
	}
	
	loop_count = 0 ; control_statement = 9;
	
	while( loop_count < control_statement )
	{
		temporary_number = number_array[ loop_count ];
		number_array[loop_count] = number_array[loop_count+1];
		number_array[loop_count+1] = temporary_number;
		
		loop_count++;
	}
	
	loop_count = 0 ; control_statement = 10;
	
	while( loop_count < control_statement )
	{
		printf(" %d in number_array[%d] \r\n" , number_array[loop_count] ,loop_count );
		loop_count++;
	}
	
	return 0;
}