/*
	Tier 3 : Part 9	:	Question 3
*/
#include<stdio.h>
#include<stdlib.h>

int print_hello_world();
int clear_screen();
int pascal_triangle();
int exit_program();
int get_int();

//here is the function for the menu
int (*menu[])() = 
{
	print_hello_world,
	clear_screen,
	pascal_triangle,
	exit_program
};

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

int print_hello_world()
{
	fprintf(stdout,"Hello world\r\n");
	main();
	return 0;
}

int pascal_triangle()
{
	int triangle[15][15];
    int x_position, y_position;
    int	number_of_rows, num = 25, lines;
	
	fprintf(stdout,"\n Enter the number of rows:");
	number_of_rows = get_int();
	
	for (x_position = 0; x_position < number_of_rows; x_position++) 
	{
		for (lines = num - 2 * x_position; lines >= 0; lines--)
			fprintf(stdout," ");
			for (y_position = 0; y_position <= x_position; y_position++) 
			{
				if (y_position == 0 || x_position == y_position) 
				{
					triangle[x_position][y_position] = 1;
                } 
				else 
				{
					triangle[x_position][y_position] = triangle[x_position - 1][y_position - 1] + triangle[x_position - 1][y_position];
                }
                fprintf(stdout,"%4d", triangle[x_position][y_position]);
            }
			fprintf(stdout,"\n");
	}
		 
	main();
	return 0;
}

int clear_screen()
{
	int clear_screen = 40;//40 lines
	int counter;
	for(counter = 0; counter<clear_screen; counter++)
	{
		fprintf(stdout,"\r\n");
	}
	main();
	return 0;
}

int exit_program()
{
	fprintf(stdout,"Ending program\r\n");
	exit(EXIT_SUCCESS);
}

int main()
{
	int program_number;
	
	fprintf(stdout,"Please enter the number for the function\r\n");
	fprintf(stdout,"1.Print hello world\r\n");
	fprintf(stdout,"2.Clean the screen\r\n");
	fprintf(stdout,"3.Print Pascals triangle\r\n");
	fprintf(stdout,"4.exit the program\r\n");
	
	program_number = get_int();
	program_number -= 1;
	
	if(program_number >= 0 && program_number <= 3)
	{
		(*menu[program_number])();
	}
	else
	{
		fprintf(stderr,"Please enter a valid option\r\n");
		main();
	}
	
	return 0;
}