/*
	Tier 3 : Part 2	:	Question 3
*/
#include<stdio.h>
#include<string.h>

struct gamer_database
{
	char gamer_name[50];
	char gamer_tag[50];
	char gamer_email[50];
	int date_joined;
	int rank;
};

struct gamer_database list[10];

int add_people()	//a simple function to add some information into the struct array
{
	strcpy( list[0].gamer_name , "John Smith"); // the only way of putting a name into a struct
	strcpy( list[0].gamer_tag , "the Chief");   // is by using strcpy
	strcpy( list[0].gamer_email , "johnsmith@gmail.com");
	list[0].date_joined = 22061992;
	list[0].rank = 2322;
	
	strcpy( list[1].gamer_name , "Joel Mcgeever");
	strcpy( list[1].gamer_tag , "The LumberJack");
	strcpy( list[1].gamer_email , "joelmcgeever@hotmail.com");
	list[1].date_joined = 06122001;
	list[1].rank = 14;
}

int main()
{
	add_people();
	
	int loop_counter = 0;
	while(loop_counter < 10)
	{
		if(list[loop_counter].rank == 0){break;}
		
		printf("Gamer Name : %s \r\n",list[loop_counter].gamer_name);
		printf("Gamer Tag  : %s \r\n",list[loop_counter].gamer_tag);
		printf("Gamer Email: %s \r\n",list[loop_counter].gamer_email);
		printf("Date_joined: %d \r\n",list[loop_counter].date_joined);
		printf("Gamer Rank : %d \r\n\n",list[loop_counter].rank);
		
		loop_counter++;
	}
	return 0;
}