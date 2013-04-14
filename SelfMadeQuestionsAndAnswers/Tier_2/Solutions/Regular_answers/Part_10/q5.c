/*
	Tier 2 : Part 10	:	Question 5
*/
#include<stdio.h>

int print_character_pointer(char *pointer[0] , int number_of_pointers);

int main()
{
	int loop_count = 0;
	char user_character,return_key;
	char *pointer[10];

	while(loop_count < 10)
	{
		printf("Please enter another character \r\n");
		scanf("%c",&*(pointer+loop_count));
		return_key = getchar();
		
		//printf("pointer holds %c ",*(pointer+loop_count)); // this works for the local but won't for the passed pointer
		
		loop_count++;
	}
	
	printf("\r\n");
	print_character_pointer(pointer,10);
	
	return 0;
}

int print_character_pointer(char *pointer[0] , int number_of_pointers)
{
	int loop_count = 0 , reverse_loop_count = number_of_pointers;
	char **temp_pointers[number_of_pointers];
	
	while(loop_count < number_of_pointers)
	{
		temp_pointers[loop_count] = pointer;
		
		//printf("%c ",&*(*temp_pointers[loop_count]));
		
		*pointer++;		
		
		loop_count++;	
	}
	
	loop_count = 0;
	while(reverse_loop_count >= 0)
	{
		*pointer--;		
		
		pointer = temp_pointers[reverse_loop_count];
		
		printf("%c ",&*(*pointer));
		
		reverse_loop_count--;
	}
	
	
	printf("\r\n");
	
	*pointer++;
	
	while(reverse_loop_count > 0)
	{
		*pointer++;
		printf("%c ",&*(*pointer));
		reverse_loop_count--;	
	}
	
	return 0;
}