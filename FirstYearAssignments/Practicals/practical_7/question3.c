/*Evan O'Keeffe
  10324289
  practical7 question3
*/
#include<stdio.h>

typedef struct
{
	char name[40];
	
	typedef struct Stats
	{
		int won;
		int lost;
		float percentage;
	}record;
	
}team;

void main()
{
	team={"Michael Murry",14,2,87,5};
}