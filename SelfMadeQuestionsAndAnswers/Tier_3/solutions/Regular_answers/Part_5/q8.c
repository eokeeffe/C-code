/*
	Tier 3 : Part 5	:	Question 8
	
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>
//base conversions for itoa
#define DEC 10
#define BIN 2
#define OCT 8
#define HEX 16

int get_number();
int use_my_printf();
int my_printf( int number_count , ... );

int myprintf(char* control_string,...)
{
	//variables for dealing with the control string
	int string_length;
	string_length = strlen(control_string);
	//start the list variable
	va_list ap;
	va_start(ap,control_string);
	
	//function variables
	double temp_double;
	char LETTER;//for the character
	char CSTRING[string_length];//for the numbers
	char* STRING_ARRAY;//for the control_string
	int character;//grab the int value from va_arg
	int number;
	int I;//counter for the loop
	
	for(I=0;I<string_length;I++)
	{
		if(control_string[I]=='%')//integer number
		{
			if(control_string[I+1]=='d'||control_string[I+1]=='i')//decimal or integer
			{
				//ERROR
				character=va_arg(ap,int);
				itoa(character,CSTRING,DEC);// the number has to be converted back to its ascii or else it will be interpreted by the
								    // putchar/puts  won't see it as the decimal value of an ascii value
				puts(CSTRING);
			}
		}
		if(control_string[I]=='%')//floating point number number
		{
			if(control_string[I+1]=='f'||control_string[I+1]=='F')//decimal or integer
			{
				//ERROR
				temp_double = va_arg(ap,double);
				
				fprintf(stdout,"%lf",temp_double);
			}
		}
		if(control_string[I]=='%')//print binary
		{
			/* //simple way of getting binary number
			if(control_string[I+1]=='b')
			{
				//ERROR
				number=va_arg(ap,int);
				itoa(number,CSTRING,BIN);// the number has to be converted back to its ascii or else it will be interpreted by the
								    // putchar/puts  won't see it as the decimal value of an ascii value
				puts(CSTRING);
				fputc('0',stdin);
			}
			*/
			if(control_string[I+1]=='b')
			{
				number = va_arg(ap,int);
				
				//deal with 2^8
				if( number < 256 )	
				{
					#define SIZE_OF_BINARY_ARRAY 8
				}
				//deal with numbers of 2^16
				if( number < 65536 )	
				{
					#undef SIZE_OF_BINARY_ARRAY
					#define SIZE_OF_BINARY_ARRAY 16
				}
				//deal with numbers of 2^32
				if( number < 4294967296 )
				{
					#undef SIZE_OF_BINARY_ARRAY
					#define SIZE_OF_BINARY_ARRAY 32
				}
				
				int binary_array[SIZE_OF_BINARY_ARRAY],loop_counter=0;
				int divisor ,clean;
				
				for(clean=0;clean<SIZE_OF_BINARY_ARRAY;clean++)
				{
					binary_array[clean]='\0';
				}
				
				divisor = number;
				
				while(divisor != 0)
				{
					binary_array[loop_counter] = (divisor%2);
					divisor /= 2;
					loop_counter++;
				}
				
				while(loop_counter > 0)
				{
					printf("%d",binary_array[loop_counter]);
					loop_counter--;
				}
				if((number%2)==0)
				{
					printf("0");
				}
				if((number%2)==1)
				{
					printf("1");
				}
			}
		}
		if(control_string[I]=='%')//octal number
		{
			if(control_string[I+1]=='o'||control_string[I+1]=='O')//print octal
			{
				//ERROR
				character=va_arg(ap,int);
				itoa(character,CSTRING,OCT);// the number has to be converted back to its ascii or else it will be interpreted by the
								    // putchar/puts  won't see it as the decimal value of an ascii value
				puts(CSTRING);
			}
		}
		if(control_string[I]=='%')//hex number
		{
			if(control_string[I+1]=='h'||control_string[I+1]=='H')//print hex
			{
				//ERROR
				character=va_arg(ap,int);
				itoa(character,CSTRING,HEX);// the number has to be converted back to its ascii or else it will be interpreted by the
								    // putchar/puts  won't see it as the decimal value of an ascii value
				puts(CSTRING);
			}
		}
		if(control_string[I]=='%')//print a string
		{
			if(control_string[I+1]=='s')//print a control_string
			{
				//ERROR
				STRING_ARRAY = va_arg(ap,char*);
				puts(STRING_ARRAY);
			}
		}
		if(control_string[I]=='%')//print a character
		{
			if(control_string[I+1]=='c')//print a control_string
			{
				//ERROR
				LETTER = va_arg(ap,int);
				putchar(LETTER);
			}
		}
	}
}

int use_my_printf() // simple use of printing 
{
	int first_number,second_number,control=0;
	double variable;
	char character;
	char sample[50];
	
	printf("Please enter a character\r\n");
	scanf("%c",&character);
	
	printf("Please enter a number\r\n");
	scanf("%d%*c",&first_number);
	
	printf("Please enter another number\r\n");
	scanf("%d%*c",&second_number);
	
	printf("Please enter a floating point number\r\n");
	scanf("%lf%*c",&variable);
	
	printf("Please enter a string\r\n");
	fgets(sample,50,stdin);
	
	myprintf("%s","\r\nthe floating point number\r\n",NULL);
	myprintf("%f %s",variable,"\r\n",0);
	
	myprintf("%s","the numbers in DEC\r\n",NULL);
	myprintf("%d %d",first_number,second_number,0);
	
	myprintf("%s","the numbers in HEX\r\n",0);
	myprintf("%h %H",first_number,second_number,0);
	
	myprintf("%s","the numbers in OCT\r\n",0);
	myprintf("%o %O",first_number,second_number,0);
	
	myprintf("%s","the numbers in BIN\r\n",0);
	myprintf("%b %s %b %s",first_number,"\r\n",second_number,"\r\n",0);
	
	myprintf("%s","control_string printed here\r\n",0);
	myprintf("%s",sample,NULL);
	myprintf("%s","character printed here\r\n",0);
	myprintf("%c",character,NULL);
}

int main()
{
	use_my_printf();
	return 0;
}

