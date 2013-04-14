/*
	Tier 3 : Part 3	:	Question 1
*/
#include<stdio.h>

enum direction
{
	NORTH,
	EAST,
	SOUTH,
	WEST
};


enum direction get_direction()
{
	int user_number;
	
	printf("Enter a number for the direction between 0-3\r\n");
	while( scanf("%d",&user_number) != 1)
	{
		printf("Please enter a number between 0-3 \r\n");
		fflush(stdin);
	}
	
	if(user_number >=4 || user_number <= -1)
	{
		get_direction();
	}
	
	return user_number;
}

int main ()
{
	enum direction my_direction;
	
	printf("Which way are you going? \r\n");
	
	my_direction = get_direction();

	switch (my_direction)
	{
		case NORTH:
		puts("NORTH");
		break;

		case SOUTH:
		puts("SOUTH");
		break;

		case EAST:
		puts("EAST");
		break;

		case WEST:
		puts("WEST");
		break;
	}

	return 0;
}