/* My Header file for question 3*/
#include<stdio.h>

int clear_screen();

int clear_screen()//the clear screen function
{
	int clean;
	for(clean=0;clean<50;clean++){printf("\r\n");}
	return 0;
}

int my_int_scanf();

int my_int_scanf()//the safe version of scanf from the input/output section 
{
	int number;
	while(scanf("%d%*c",&number)!=1)
	{
		fflush(stdin);
	}
	return number;
}

char my_gets(char string_input[0],int limit);

char my_gets(char string_input[0],int limit) // a safe version of gets that will not allow for string
{											 // overflow
	//char string_input[100];
	int next_character=0,get_character;
	int clean;
	
	for(clean=0;clean<limit;clean++)
	{
		string_input[clean]='\0';
	}
	
	while(get_character!='\r'&&get_character!='\n'&&next_character < limit) // keep the loop going as the enter isnt pushed
	{																		// and as long as the string can contain it
		get_character = fgetc(stdin);
		string_input[next_character] = get_character;
		next_character++;
	}
	
	fflush(stdin); //anything else will be discarded from the buffer
	
	return string_input[0];
}