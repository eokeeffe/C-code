/*
	Tier 2 : Part 9	:	Question 9
	
	To show what I mean I've made an example here
	the differences between the two declarations are 
	
	char* string is a pointer to the sequential array of characters , this pointer can't be changed or else it will
	yield undefineable behaviour , so this expression should really be used when its initialized with a constant string
	e.g const char* string = "Hello World";
	This statement is really what should be used as re-writing this string would probably produce an error like below
	
	char string[50] is an array of characters that have been allocated by the programmer in memory
	the difference is that the memory in this case can be written to again and again without difficulty
	
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char *array = "Hello World";
	char array_1[12]="Hello World";
	
	printf("%s string 1\r\n",array);
	printf("%s string 2\r\n",array_1);
	
	strcpy(array,"Hello Android");
	strcpy(array_1,"Hello WebOS");
	
	printf("%s string 1\r\n",array);
	printf("%s string 2\r\n",array_1);
	
	return 0;
}