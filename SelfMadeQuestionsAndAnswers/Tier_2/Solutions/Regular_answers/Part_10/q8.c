/*
	Tier 2 : Part 10	:	Question 8
*/
#include<stdio.h>

int find_letter(char *pointer,char character_to_search_for);

int main()
{
	int loop_count = 0;
	char *pointer_1,user_string[40];
	char character_to_search_for,return_key;
	
	printf("please enter a string\r\n");
	fgets(user_string,40,stdin);
	
	pointer_1 = &user_string[0];
	
	printf("please enter a charcter to search for in the string\r\n");
	character_to_search_for = getchar();
	
	find_letter( pointer_1 ,character_to_search_for);
	
	return 0;
}

int find_letter(char *pointer,char character_to_search_for)
{
	int loop_count = 0 , array_counter=0, array[40];
	int clean;
	char temp_comparison_character;
	
	for(clean=0;clean<40;clean++){array[clean]=0;}
	
	while(loop_count  < 40)
	{
		temp_comparison_character = *pointer;
		
		if(temp_comparison_character == character_to_search_for)
		{
			array[array_counter] = (int)pointer;
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
			printf("%c occurs in location %d in memory \r\n",character_to_search_for,array[loop_count]);
		}
		loop_count++;
	}
	
	return ;
}