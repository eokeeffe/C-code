/*
	Tier 2 : Part 10	:	Question 4
*/
#include<stdio.h>

int print_character_pointer(char *pointer[0] , int number_of_pointer);

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
		
		printf("pointer holds %c ",*(pointer+loop_count)); // this works for the local but won't for the passed pointer
		
		loop_count++;
	}
	
	printf("\r\n");
	print_character_pointer(pointer,10);
	
	return 0;
}

int print_character_pointer(char *pointer[0] , int number_of_pointer)
{
	int loop_count = 0;
	while(loop_count < 10)
	{
		printf("%c ",&*(*pointer));	// so this will more than likely look like something that shouldn't work 
									// this will get whats at the address of this pointer and print it
		*pointer++;		//the pointer is then incremented onto the next memory location as they sequential so 
						// this is all thats needed to get th enext character
		loop_count++;	// we just use this as a saftey counter
	}
	
	return 0;
}