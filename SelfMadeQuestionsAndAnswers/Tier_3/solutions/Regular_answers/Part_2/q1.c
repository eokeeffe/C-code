/*
	Tier 3 : Part 2	:	Question 1
*/
#include<stdio.h>

struct phonebook
{
	char country_name[50];
	int phone_extension;
}access;

struct phonebook list[]=
{
	{"Ireland",353},
	{"England",44},
	{"France",33},
	{"Germany",49},
	{"Greece",30},
};

int main()
{
	int loop_counter = 0;
	
	while(loop_counter < 5)
	{
		printf("%s : %d\r\n",list[loop_counter].country_name,list[loop_counter].phone_extension);
		loop_counter++;
	}
	return 0;
}