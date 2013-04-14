/*
	Tier 1 : Part 9	:	Question 10
	
	If you did this program then well done 
	Your now ready to give the next section a try 
	Some parts of this are going to be shown in greater detail in the next Tier
	
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int clear_screen();
int print_menu();
int date_and_time();
int draw_times_table();
int menu_input();
int exit_program();

int main()
{
	print_menu();
	return 0;
}

int print_menu()
{
	clear_screen();
	
	int user_input=0;
	
	printf("Please enter a number to access the function\r\n");
	printf("1. Clear the screen\r\n");
	printf("2. print a 10x10 multiplication table\r\n");
	printf("3. Print the current date and time\r\n");
	printf("4.exit the program\r\n");
	user_input = menu_input();
	
	if(user_input==1){	clear_screen();	print_menu(); }
	if(user_input==2){	draw_times_table();	}
	if(user_input==3){	date_and_time();	}
	if(user_input==4){	exit_program();	}
	else
		{
			printf("Please enter a proper choice\r\n");
			print_menu();
		}
}

int menu_input()
{
	int user_input;
	
	while( scanf("%d%*c",&user_input)!=1)
	{
		fflush(stdin);	//this will be explained in the next  Tier 
	}
	
	return user_input;
}

int clear_screen()
{
	int screen_lines_to_be_cleaned = 0;
	int number_of_lines = 40;
	
	while(screen_lines_to_be_cleaned < number_of_lines )
	{
		printf("\r\n");
		screen_lines_to_be_cleaned++;
	}
	
	return 0;
}

int date_and_time()
{
	time_t mytime;
	mytime = time(NULL);
	printf(ctime(&mytime));
	
	return 0;
	print_menu();
}

int draw_times_table()
{
	int vertical_count,horizontal_count;
	int control_statement=10 , multiplier, one=1;
	
	for(vertical_count=0;vertical_count<control_statement;vertical_count++)
	{
		multiplier = vertical_count;
		for(horizontal_count=0;horizontal_count<control_statement;horizontal_count++)
		{
			if(multiplier==1)
			{
				printf(" %d ",multiplier*one); 
			}
			if(multiplier*horizontal_count >= 10)
			{
				printf(" %d ",multiplier*horizontal_count); 
			}
			if(multiplier!=1&&multiplier!=10)
			{
				printf(" %d ",multiplier*horizontal_count);
			}
		}
		printf("\r\n");
	}
	return 0;
	print_menu();
}

int exit_program()
{
	exit(0);
}